#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#define TEST
using namespace std;

struct Data {
    vector<double> features;
    int label;
    Data(vector<double> f, int l) : features(f), label(l)
    {}
};
struct Param {
    vector<double> wtSet;
    double b;
};


class LR {
public:
    void train();
    void predict();
    int loadModel();
    int storeModel();
    LR(string trainFile, string testFile, string predictOutFile);

private:
    vector<Data> trainDataSet;
    vector<Data> testDataSet;
    vector<int> predictVec;
    Param param;
    string trainFile;
    string testFile;
    string predictOutFile;
    string weightParamFile = "modelweight.txt";

private:
    bool init();
    bool loadTrainData();
    bool loadTestData();
    int storePredict(vector<int> &predict);
    void initParam();
    double wxbCalc(const Data &data);
    double sigmoidCalc(const double wxb);
    double lossCal();
    double gradientSlope(const vector<Data> &dataSet, int index, const vector<double> &sigmoidVec);
    double gradientSolpeb(const vector<Data> &dataSet, const vector<double> &sigmoidVec);

private:
    int featuresNum;
    const double wtInitV = 0; //权重初始值
    const double stepSize = 0.01; //学习率
    const int maxIterTimes = 10; //训练迭代次数
    const double predictTrueThresh = 0.5; //预测准确阈值
    const int train_show_step = 10; //训练展示步
};

LR::LR(string trainF, string testF, string predictOutF)
{
    trainFile = trainF;
    testFile = testF;
    predictOutFile = predictOutF;
    featuresNum = 0;
    init();
}

bool LR::loadTrainData()
{
    ifstream infile(trainFile.c_str()); //open构造函数直接读入文件 ifstream读入,ofstream写入
    string line;

    if (!infile) {
        cout << "打开训练文件失败" << endl;
        exit(0);
    }

    while (infile) {
        getline(infile, line);
        if (line.size() > featuresNum) {
            stringstream sin(line);
            char ch;
            double dataV;
            int i;
            vector<double> feature;
            i = 0;

            while (sin) {
                char c = sin.peek(); //查看下一个数据,并不读取
                if (int(c) != -1) { //EOF(-1)表示读到行尾没数据了
                    sin >> dataV;
                    feature.push_back(dataV); //读入特征数据值
                    sin >> ch; //逗号分割
                    i++;
                } else {
                    cout << "训练文件数据格式不正确，出错行为" << (trainDataSet.size() + 1) << "行" << endl;
                    return false;
                }
            }
            int ftf; //最后一个数据是标签
            ftf = (int)feature.back();
            feature.pop_back();
            trainDataSet.push_back(Data(feature, ftf)); //每一行为一个数据段
        }
    }
    infile.close();
    return true; //载入数据成功
}

void LR::initParam()
{
    int i;
    for (i = 0; i < featuresNum; i++) {
        param.wtSet.push_back(wtInitV); //初始化参数都为1
    }
    param.b=0.0;
}

bool LR::init() //初始化过程,包括载入数据,初始化权值
{
    trainDataSet.clear();
    bool status = loadTrainData();
    if (status != true) {
        return false;
    }
    featuresNum = trainDataSet[0].features.size(); //特征个数
    param.wtSet.clear();
    initParam();
    return true;
}


double LR::wxbCalc(const Data &data) //预测值的计算,其实就是w*x+b计算过程
{
    double mulSum = 0.0L;
    int i;
    double wtv, feav;
    for (i = 0; i < param.wtSet.size(); i++) {
        wtv = param.wtSet[i]; //权值w的值
        feav = data.features[i]; //特征x的值
        mulSum += wtv * feav;
    }
    return mulSum+param.b; //预测值
}

inline double LR::sigmoidCalc(const double wxb) //sigmoid函数出现某类的概率 f'=f*(1-f)
{
    double expv = exp(-1.0 * wxb);
    double expvInv = 1.0/ (1.0 + expv);
    return expvInv;
}


double LR::lossCal() //损失计算 交叉熵 loss=-(ylogp+(1-y)log(1-p)) y是标签,p是概率
{
    double lossV = 0.0L;
    int i;

    for (i = 0; i < trainDataSet.size(); i++) {
        lossV -= trainDataSet[i].label * log(sigmoidCalc(wxbCalc(trainDataSet[i])));
        lossV -= (1 - trainDataSet[i].label) * log(1.0 - sigmoidCalc(wxbCalc(trainDataSet[i])));
    }
    lossV /= trainDataSet.size(); //平均损失
    return lossV;
}

//梯度下降优化 Ji'=(f(wxi+b)-label)*xi
double LR::gradientSlope(const vector<Data> &dataSet, int index, const vector<double> &sigmoidVec)
{
    double gsV = 0.0L;
    int i;
    double sigv, label;
    for (i = 0; i < dataSet.size(); i++) {
        sigv = sigmoidVec[i];
        label = dataSet[i].label;
        gsV += (label - sigv) * (dataSet[i].features[index]); //这里label-sigv,后面更新权重就是加
    }

    gsV = gsV / dataSet.size();
    return gsV;
}


void LR::train() //训练过程
{
    double sigmoidVal;
    double wxbVal;
    int i, j;

    for (i = 0; i < maxIterTimes; i++) {
        vector<double> sigmoidVec;

        for (j = 0; j < trainDataSet.size(); j++) {
            wxbVal = wxbCalc(trainDataSet[j]);
            sigmoidVal = sigmoidCalc(wxbVal);
            sigmoidVec.push_back(sigmoidVal);
        }

        for (j = 0; j < param.wtSet.size(); j++) { //前面反了过来,所以这里是加号
            param.wtSet[j] += stepSize * gradientSlope(trainDataSet, j, sigmoidVec);
        }

        param.b += stepSize * gradientSolpeb(trainDataSet,sigmoidVec);

        if (i % train_show_step == 0) {
            cout << "iter " << i << ". updated weight value is : ";
            for (j = 0; j < param.wtSet.size(); j++) {
                cout << param.wtSet[j] << "  ";
            }
            cout<<param.b;
            cout << endl;
        }
    }
}

void LR::predict() //预测过程
{
    double sigVal;
    int predictVal;

    loadTestData(); //载入测试数据
    for (int j = 0; j < testDataSet.size(); j++) {
        sigVal = sigmoidCalc(wxbCalc(testDataSet[j]));
        predictVal = sigVal >= predictTrueThresh ? 1 : 0; //概率超过阈值为1类,否则为0
        predictVec.push_back(predictVal);
    }

    storePredict(predictVec); //存储test结果,比较准确率
}

int LR::loadModel() //载入保存好的权值
{
    string line;
    int i;
    vector<double> wtTmp;
    double dbt;

    ifstream fin(weightParamFile.c_str());
    if (!fin) {
        cout << "打开模型参数文件失败" << endl;
        exit(0);
    }

    getline(fin, line);
    stringstream sin(line);
    for (i = 0; i < featuresNum; i++) {
        char c = sin.peek();
        if (c == -1) {
            cout << "模型参数数量少于特征数量，退出" << endl;
            return -1;
        }
        sin >> dbt;
        wtTmp.push_back(dbt);
    }
    sin>>dbt;
    param.b=dbt;
    param.wtSet.swap(wtTmp); //交换到默认的权值序列中
    fin.close();
    return 0;
}

int LR::storeModel() //保存训练好的系数
{
    string line;
    int i;

    ofstream fout(weightParamFile.c_str()); //注意这里是ofstream写入文件
    if (!fout.is_open()) {
        cout << "打开模型参数文件失败" << endl;
    }
    if (param.wtSet.size() < featuresNum) {
        cout << "wtSet size is " << param.wtSet.size() << endl;
    }
    for (i = 0; i < featuresNum; i++) {
        fout << param.wtSet[i] << " ";
    }
    fout<<param.b;
    fout.close();
    return 0;
}


bool LR::loadTestData()
{
    ifstream infile(testFile.c_str());
    string lineTitle;

    if (!infile) {
        cout << "打开测试文件失败" << endl;
        exit(0);
    }

    while (infile) { //和载入训练数据一样操作
        vector<double> feature;
        string line;
        getline(infile, line);
        if (line.size() > featuresNum) {
            stringstream sin(line);
            double dataV;
            int i;
            char ch;
            i = 0;
            while (i < featuresNum && sin) {
                char c = sin.peek();
                if (int(c) != -1) {
                    sin >> dataV;
                    feature.push_back(dataV);
                    sin >> ch;
                    i++;
                } else {
                    cout << "测试文件数据格式不正确" << endl;
                    return false;
                }
            }
            testDataSet.push_back(Data(feature, 0)); //先默认标签为0
        }
    }

    infile.close(); //使用完关闭
    return true;
}

bool loadAnswerData(string awFile, vector<int> &awVec) //与答案进行比较
{
    ifstream infile(awFile.c_str());
    if (!infile) {
        cout << "打开答案文件失败" << endl;
        exit(0);
    }

    while (infile) {
        string line;
        int aw;
        getline(infile, line);
        if (line.size() > 0) {
            stringstream sin(line);
            sin >> aw;
            awVec.push_back(aw);
        }
    }

    infile.close();
    return true;
}

int LR::storePredict(vector<int> &predict) //保存预测结果
{
    string line;
    int i;

    ofstream fout(predictOutFile.c_str());
    if (!fout.is_open()) {
        cout << "打开预测结果文件失败" << endl;
    }
    for (i = 0; i < predict.size(); i++) {
        fout << predict[i] << endl;
    }
    fout.close();
    return 0;
}

double LR::gradientSolpeb(const vector<Data> &dataSet, const vector<double> &sigmoidVec) {
    double gsV = 0.0L;
    int i;
    double sigv, label;
    for (i = 0; i < dataSet.size(); i++) {
        sigv = sigmoidVec[i];
        label = dataSet[i].label;
        gsV += (label - sigv); //这里label-sigv,后面更新权重就是加
    }

    gsV = gsV / dataSet.size();
    return gsV;
}


int main(int argc, char *argv[])
{
    vector<int> answerVec;
    vector<int> predictVec;
    int correctCount;
    double accurate;
    string trainFile = "/home/liu/pycharm_study/projects/superpixels/data/train_data.txt";
    string testFile = "/home/liu/pycharm_study/projects/superpixels/data/test_data.txt";
    string predictFile = "/home/liu/pycharm_study/projects/superpixels/data/result.txt";

    string answerFile = "/home/liu/pycharm_study/projects/superpixels/data/answer.txt";

    LR logist(trainFile, testFile, predictFile);

    cout << "ready to train model" << endl;
    logist.train();

    cout << "training ends, ready to store the model" << endl;
    logist.storeModel();

#ifdef TEST
    cout << "ready to load answer data" << endl;
    loadAnswerData(answerFile, answerVec);
#endif

    cout << "let's have a prediction test" << endl;
    logist.loadModel();
    logist.predict();

#ifdef TEST
    loadAnswerData(predictFile, predictVec);
    cout << "test data set size is " << predictVec.size() << endl;
    correctCount = 0;
    for (int j = 0; j < predictVec.size(); j++) {
        if (j < answerVec.size()) {
            if (answerVec[j] == predictVec[j]) {
                correctCount++;
            }
        } else {
            cout << "answer size less than the real predicted value" << endl;
        }
    }

    accurate = ((double)correctCount) / answerVec.size();
    cout << "the prediction accuracy is " << accurate << endl;
#endif

    return 0;
}
