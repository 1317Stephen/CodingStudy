/*
 * < Cracking The Coding Interview 6/E >
 * Problem #1.2 Two strings are same if they are ordered (Permutate)
 * 
 * Author: YeEun Ko
 * 
 */

#include <iostream>
#include<string>
#include<algorithm>

using namespace std;
bool isPermutationSort(string a, string b);
bool isPermutate(string s, string t);   //ONLY can use when strings are the ASCII code

int main()
{
    cout<<isPermutationSort("./`|:'@)]}<", ":.}`'@<|)]/")<<"\n";
    cout<<isPermutate("./`|:'@)]}<", ":.}`'@<|)]/")<<"\n";
    return 0;
}
bool isPermutationSort(string a, string b)
{
    sort(a.begin(),a.end());
    sort(b.begin(), b.end());

    return(!a.compare(b));
}
bool isPermutate(string s, string t)
{
    //ONLY can use when the string is ASCII code, 128 letters
    if(s.size()!=t.size())
    {
        return false;
    }
    int letters[128]={0};
    for(char &c:s)
    {
        letters[c]++;
    }
    for(char &c:t)
    {
        letters[c]--;
        if(letters[c]<0)
        {
            return false;
        }
    }
    return true;

}
