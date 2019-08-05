/*
 * Google Kick Start 2019 Round D #1. X or What?
 * Author: YeEun Ko
 */
#include<iostream>

using namespace std;

int a[100000]={0};

int countOnes(int numb);
bool isEvenXOR(int *a, int start, int end);

int main()
{
    int i,j,k;
    int cases=0;
    int nArray, nModification;
    int qIndex, modValue;

    cin>>cases;
    for(i=1; i<=cases; i++)
    {
        printf("Case #%d: ", i);
        cin>>nArray>>nModification;
        for(j=0; j<nArray; j++)
        {
            cin>>a[j];
        }
        for(j=0; j<nModification; j++)
        {
            cin>>qIndex>>modValue;
            a[qIndex]=modValue;

            int start=0, end=nArray-1;
            for(k=nArray; k>0; k--)
            {
                end=start+k-1;
                if(isEvenXOR(a, start, end)) break;
                else
                {
                    start++; end=start+k-1;
                    if(end<nArray)k++;
                    else start=0;
                }
                
            }   
            cout<<k<<" ";
        }

        
    }
    return 0;
}
bool isEvenXOR(int *a, int start, int end)
{
    int xorSum=0;
    for(int i=start; i<=end; i++)
    {
        xorSum^=a[i];
    }
    return countOnes(xorSum)%2==0;
}
int countOnes(int numb)
{
    int count=0;
    while (numb!=0)
    {
        numb = numb & (numb-1);
        count++;
    }
    return count;
}