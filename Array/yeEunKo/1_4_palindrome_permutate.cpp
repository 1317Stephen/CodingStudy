/*
 * < Cracking The Coding Interview 6/E >
 * Problem #1.4 Is a strings palindrome permutation?
 * 
 * Author: YeEun Ko
 * 
 */
#include<iostream>
#include<string>
#include<algorithm>
#include<time.h>
#include <limits>


using namespace std;
int isPalindrome(string a); //TIMEOUT!!
bool isPalindromeIndex(string str);

int toggle(int bitVector, int index);   //on/off switch
int createBitVector(string str);
bool isPermutationPalindrome(string str);

int main()
{
    // for(int i=0; i<1000; i++)
    // {
    //     cout<<isPalindrome("_@~*@(,./|`")<<"\n";
    //     cout<<isPalindrome("abcba")<<"\n";
    // }
    cout<<isPalindromeIndex("abba")<<"\n";
    cout<<isPalindromeIndex("//||//")<<"\n";
    cout<<isPermutationPalindrome("abab")<<"\n";
    cout<<isPermutationPalindrome("eoneoneoneond")<<"\n";
    return 0;
    
}
int isPalindrome(string a)
{
    /* Check whether a string is a palindrome
     * This way usually takes lots of time- TIMEOUT ERROR
     */
    string reverseStr = a;
    reverse(reverseStr.begin(), reverseStr.end());
    if(a.compare(reverseStr)==0)
        return 1;
    else
        return 0;
}
bool isPalindromeIndex(string str)
{
    int i=0;
    int strSize=str.size();
    for(i=0; i<strSize/2-1; i++)
    {
        if(str[i]!=str[strSize-i-1])
        {
            return false;
        }
    }
    return true;
}

int toggle(int bitVector, int index)
{
    if(index<0)
    {
        return bitVector;
    }
    int mask=1<<index;
    if(bitVector&mask==0  )
    {
        bitVector |= mask;
    }
    else
    {
        bitVector &= ~mask;
    }
    return bitVector;

}
int createBitVector(string str)
{
    int bitVector=0;
    for(char &c:str)
    {
        int value=(int)(c-'a');
        bitVector=toggle(bitVector, value);
    }
    return bitVector;
}

bool checkOnlyOneOddNumber(int bitVector)
{
    return (bitVector&(bitVector-1)==0 );
}

bool isPermutationPalindrome(string str)
{
    int bitVector=createBitVector(str);
    return bitVector==0||checkOnlyOneOddNumber(bitVector);

}
