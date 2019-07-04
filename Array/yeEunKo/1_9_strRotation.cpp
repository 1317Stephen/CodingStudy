/*
 * < Cracking The Coding Interview 6/E >
 * Problem #1.9 Are the two strings the same if rotate one?
 * Ex) waterbottle & erbottlewat
 * 
 * Author: YeEun Ko
 */

#include<iostream>

using namespace std;


bool rotateSame(string a, string b);
int main()
{
    cout<<rotateSame("waterbottle","erbottlewat" );
    return 0;
}
bool rotateSame(string a, string b)
{
    if(a.size()!=b.size())
    {
        return false;
    }
    string totalStr=a.append(a);
    if(totalStr.find(b)!=string::npos)
    {
        return true;
    }
    return false;

}

