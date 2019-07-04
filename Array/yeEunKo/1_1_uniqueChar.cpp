/*
 * < Cracking The Coding Interview 6/E >
 * Problem #1.1 Duplicate Character in a string
 * 
 * Author: YeEun Ko
 * 
 */
#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;

int isDuplicateChar(string a);      //Check duplicate character using Map
bool isUniqueCharArray(string str); //Check duplicate ASCII character using Array


int main()
{
    cout<<isDuplicateChar("abc:_ds ` #1-9=/']") << "\n";
    cout<<isUniqueCharArray("abc:_ds ` #1-9=/']")<<"\n";
    return 0;
}

int isDuplicateChar(string a)
{
    int i;
    int isDuplicate=0;
    map<char, int>alphabet;
    pair<map<char, int>::iterator,bool>ret;

    for(i=0; i<a.size(); i++)
    {
        ret = alphabet.insert(pair<char, int>(a[i],1));
        if(ret.second==false)
        {
            alphabet[a[i]]++;
            isDuplicate=1;
            break;
        }
    }  
    return isDuplicate;  
}

bool isUniqueCharArray(string str)
{
    /*Suppose that the number of characters are less than 128, ASCII code */
    if(str.size()>128)
    {
        return false;
    }
    int i=0;
    bool char_set[128]={0};

    for(char &c:str)
    {
        int val = c;
        // printf("[c:val] %c: %d -> %d \n", c,val, char_set[val]);

        if(char_set[val])
        {
            return false;
        }
        char_set[val] = true;
    }
    return true;
}
