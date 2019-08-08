#include<iostream>
using namespace std;
long long pinary[91]={0};
int main()
{
    int i;
    int digit=0;
    cin>>digit;
    pinary[1]=1, pinary[2]=1;
    for(i=3; i<=digit; i++)
    {
        pinary[i]=pinary[i-1]+pinary[i-2];
    }
    cout<<pinary[digit];
    return 0;
}