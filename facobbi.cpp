//
// Created by liu on 19-6-10.
//
#include<iostream>

using namespace std;

int facobbi(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n*facobbi(n-1);
}
