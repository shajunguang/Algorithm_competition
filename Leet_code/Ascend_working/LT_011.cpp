/*
 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 思路：双指针，找出单调性即可，值大的指针不动，值小的移动保证面积单调递增即可O(n)
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,n=height.size(),j=n-1,res=0;
        while(i<j){
            int h=min(height[i],height[j]);
            res=max(res,h*(j-i));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return res;
    }
};