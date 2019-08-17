#include<iostream>
#include<string>
using namespace std;
int isPalindrome(string str);
int main()
{
    string str;
    cin>>str;
    cout<<isPalindrome(str);
    return 0;
}
int isPalindrome(string str)
{
    int isPal=1;
    int i;
    for(i=0; i<str.size()/2; i++)
    {
        if(str[i]!=str[str.size()-i-1])
        {
            isPal=0;
            break;
        }
    }
    return isPal;
}