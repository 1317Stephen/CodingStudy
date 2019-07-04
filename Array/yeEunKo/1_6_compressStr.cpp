/*
 * < Cracking The Coding Interview 6/E >
 * Problem #1.6 Compress String
 *  Ex) aabccca -> a2b1c3a1
 * 
 * Author: YeEun Ko
 * 
 */
#include<iostream>
#include<string>

using namespace std;

string compressStr(string str);
int main()
{
    cout<<compressStr("aabccca-");
    return 0;
}
string compressStr(string str)
{
    int index;
    int duplicateStart=0;
    string strPress="";
    for(index=1; index<str.size(); index++)
    {
        if(str[index]!=str[index-1] || index==(str.size()-1) )
        {
            //printf("%c%d", str[index-1], index-duplicateStart);
            strPress.append(str[index-1]+ to_string(index-duplicateStart));
            duplicateStart = index;
        }
    }
    
    //printf("%c%d\n", str[index-1], index-duplicateStart);
    strPress.append(str[index-1]+ to_string(index-duplicateStart));
    return strPress;
}