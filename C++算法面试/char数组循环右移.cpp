#include<bits/stdc++.h>
using namespace std;

typedef struct tagWaveFormat
{
    char cRiffFlag[4];
    uint32_t nFileLen;
    char cWaveFlag[4];
    char cFmtFlag[4];
    char cTransition[4];
    uint16_t nFormatTag ;
    uint16_t nChannels;
    uint16_t nSamplesPerSec;
    uint32_t nAvgBytesperSec;
    uint16_t nBlockAlign;
    uint16_t nBitNumPerSample;
    char cDataFlag[4];
    uint32_t nAudioLength;
} WAVEFORMAT;

const int MAXSIZE=100;
void LoopMove(char* str, int steps){
    int len = strlen(str);
    char tmp[MAXSIZE];
    strcpy(tmp, str+len-steps);
    strcpy(tmp+steps, str);
    *(tmp+len) = '\0'; //这步加结束符,截断后面循环部分
    strcpy(str, tmp); //这部深拷贝
}
int main()
{
    char str[]="abcdefghi";
    LoopMove(str,2);
    cout<<str;
    return 0;
}