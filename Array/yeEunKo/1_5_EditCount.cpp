/*
 * < Cracking The Coding Interview 6/E >
 * Problem #1.5 Count the edit times that make a string A to a string B.
 * String Edit: Insert, Remove, Substitute
 * 
 * Author: YeEun Ko
 * 
 */
#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;
bool isEditOnce(string a, string b);
bool isReplaceOnce(string a, string b);
bool isAddRemoveOnce(string a, string b);   //a.size() > b.size()

int main()
{
    cout<<isEditOnce(""," ")<<"\n";
    cout<<isEditOnce("_  _","_ _")<<"\n";
    cout<<isEditOnce("abb","abc")<<"\n";
    return 0;
}
bool isReplaceOnce(string a, string b)
{
    int i=0, countDiff=0;
    for(i=0; i<a.size(); i++)
    {
        if(a[i]!=b[i])
        {
            countDiff++;
        }
        if(countDiff>1)
        {
            return false;
        }
    }
    return true;
}
bool isAddRemoveOnce(string a, string b)
{
    /* a.size() > b.size()
     */
    int iBigger=0, iSmaller=0;
    for(iBigger=0; iBigger<a.size(); iBigger++)
    {
        if(a[iBigger]!=b[iBigger])
        {
            iBigger++;
        }
        if(iBigger-iSmaller>1)
        {
            return false;
        }
        if(a[iBigger]!=b[iSmaller]) 
        {
            return false;
        }
        iSmaller++;
    }
    return true;
}
bool isEditOnce(string a, string b)
{
    if(a.size()==b.size())
    {
        return isReplaceOnce(a,b);
    }
    else if(a.size()-b.size()==1 )  // a.size() > b.size()
    { 
        return isAddRemoveOnce(a,b);
    }
    else if(b.size()-a.size()==1) //a.size() < b.size()
    {
        return isAddRemoveOnce(b,a);
    }
    return false;
}
