#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i;
    int climb[302]={0}, stairs[302]={0};
    int nStairs=0;
    cin>>nStairs;
    for(i=1; i<=nStairs; i++)
    {
        cin>>stairs[i];
    }
    climb[1]=stairs[1];
    climb[2] = max(stairs[1]+stairs[2], stairs[2]);
    climb[3] = max(stairs[1]+stairs[3], stairs[2]+stairs[3]);
    
    for(i=4; i<=nStairs; i++)
    {
        climb[i]=max(stairs[i]+climb[i-2], stairs[i]+stairs[i-1]+climb[i-3]);
    }
    cout<<climb[nStairs];

    return 0;
}