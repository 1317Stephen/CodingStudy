/*
 * < Cracking The Coding Interview 6/E >
 * Problem #2.6 Check whether the list is the palindrome
 * 
 * Author: YeEun Ko
 * 
 */
#include"list.h"
#include<list>
#include<iostream>
#include<algorithm>
using namespace myList;
using namespace std;

int main()
{
    /* Using Library */
    std::list <int> ls;
    
    ls.push_back(1);
    ls.push_back(3);
    ls.push_back(1);

    std::list<int>rev=ls;    
    rev.reverse();

    if(equal(ls.begin(), ls.end(), rev.begin()) )
    {
        cout<<"equal"<<"\n";
    }
    else
    {
        cout<<"differenct"<<"\n";
    }
    
    /* Without Lib cbrary */
    


    return 0;
}
