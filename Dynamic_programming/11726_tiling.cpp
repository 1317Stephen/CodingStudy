#include<iostream>

using namespace std;
int filling[1002]={0};
int main()
{
    int iSize=0;
    int size;   //2*n
    cin>>size;    

    filling[1]=1; //2*1(1)
    filling[2]=2; //2*1(2)  1*2(2)

    for(iSize=3; iSize<=size; iSize++)
    {
        filling[iSize]=filling[iSize-2]%10007+filling[iSize-1]%10007;
    }
    cout<<filling[size]%10007;
    return 0;
}