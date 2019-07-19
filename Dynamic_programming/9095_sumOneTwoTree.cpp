#include<iostream>
using namespace std;
int arr[12]={0};
int main()
{
    int i=0;
    int cases=0;

    arr[1]=1;   //1
    arr[2]=2;   //1+1 2
    arr[3]=4;   //1+1+1  1+2  2+1  3
    arr[4]=7;   //3+1(3)  1+3(3)  2+2(1)

    cin>>cases;
    while(cases>0)
    {
        int i;
        int numb;
        cin>>numb;
        for(i=4; i<=numb; i++)
        {
            arr[i] = arr[i-2]+arr[i-1]+arr[i-3];
        }
        cout<<arr[numb]<<"\n";
        cases--;
    }
    return 0;
}