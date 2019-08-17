#include<iostream>
#include<algorithm>
using namespace std;
int quantity[10001]={0};
int cntMax[10001]={0};
int main()
{
    int i;
    int nWines;    
    cin>>nWines;
    for(i=0; i<nWines; i++)
    {
        cin>>quantity[i];
    }
    cntMax[0]=quantity[0];
    cntMax[1]=quantity[0]+quantity[1];
    cntMax[2]=max(quantity[0]+quantity[2], quantity[1]+quantity[2]);
    cntMax[3]=max(quantity[3]+cntMax[1], quantity[3]+cntMax[0]+quantity[2]);
    for(i=4; i<nWines; i++)
    {
        cntMax[i]=max(cntMax[i-4]+quantity[i]+quantity[i-1], max(quantity[i]+cntMax[i-2], quantity[i]+cntMax[i-3]+quantity[i-1]));
    }
    cout<<max(cntMax[nWines-1], cntMax[nWines-2]);
    return 0;
}