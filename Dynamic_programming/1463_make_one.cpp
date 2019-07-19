#include <iostream>
#include<algorithm>
using namespace std;
long long arr[1000001]={0};
int main()
{
    int i;
    int nCount=0, nTwo=0;
    long long n;
    cin>>n;
    
    for(i=2; i<=n; i++)
    {
        arr[i]=arr[i-1]+1;
        if(i%2==0)
        {
            arr[i] = min(arr[i], arr[i/2]+1);
        }
        if(i%3==0)
        {
            arr[i]=min(arr[i], arr[i/3]+1);
        }
    }
    cout<<arr[n];

/*
    while(n!=1)
    {
        if(n%4!=0 && n%3!=0)
        {
            n--;
            nCount++;
            cout<<n<<"\n";
        }
        if(n%3==0)
        {
            n/=3;
            nCount++;
            cout<<n<<"\n";
        }
        else if(n%2==0)
        {
            n/=2;
            nCount++;
            cout<<n<<"\n";
        }
    }
    cout<<nCount;
*/

    /*
    if(n>=3)
    {
        nCount+=n/3;
        n-= nCount*3;
        if(n<=1 && (n+nCount*3)%3!=0)nCount++;
        printf("3:%d\n", nCount);
    }
    if(n>=2)
    {
        nTwo+=n/2;
        n-=2*nTwo;
        if((n<=1 && (n+nTwo*2)%2!=0) )nTwo++;
        printf("2:%d\n", nTwo);
    }
    if(n!=1)
    {
        nCount+=n;
    }
    cout<<nCount+nTwo;
    */
    return 0;
}