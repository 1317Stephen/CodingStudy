#include <iostream>
#include<algorithm>
using namespace std;

int price[1001][3]={0};
int minPrice[1001][2]={0};

int secondMin(int *arr, int size, int *index);
int main()
{
    int r,g,b;
    int i;
    int house;
    int sum=0, minIndex=0;
    cin>>house;

    cin>>price[0][0]>>price[0][1]>>price[0][2];
    for(i=1; i<house; i++)
    {
        cin>>r>>g>>b;
        price[i][0]=min(price[i-1][1],price[i-1][2])+r;
        price[i][1]=min(price[i-1][0],price[i-1][2])+g;
        price[i][2]=min(price[i-1][0],price[i-1][1])+b;
    }
    cout<<min(price[house-1][0], min(price[house-1][1],price[house-1][2]));
    
    return 0;
}
int secondMin(int *arr, int size, int *index)
{
    int smallest, secondMin, iSmall;
    if(arr[0]<arr[1])
    {
        smallest=arr[0];    iSmall=0;
        secondMin=arr[1];   *index=1;
    }
    else
    {
        smallest=arr[1];    iSmall=1;
        secondMin=arr[0];   *index=0;
    }
    for(int i=0; i<size; i++)
    {
        if(arr[i]<smallest)
        {
            *index=iSmall;
            smallest=arr[i];
            secondMin=smallest;
            iSmall=i;
        }
        if(arr[i]>smallest && secondMin>arr[i])
        {
            secondMin=arr[i];
            *index=i;
        }
    }
    return secondMin;
}