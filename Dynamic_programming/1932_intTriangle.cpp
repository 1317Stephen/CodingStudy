#include<iostream>
#include<algorithm>
using namespace std;
int maxSum[501]={0};
int triangle[502][502]={0};
int main()
{
    int i, j;
    int size;
    cin>>size;

    cin>>triangle[1][0];
    for(i=2; i<=size; i++)
    {
        for(j=0; j<i; j++)
        {
            int value;
            cin>>value;
            if(j==0)triangle[i][j]=triangle[i-1][0]+value;
            else if(j==i-1)triangle[i][j]=triangle[i-1][j-1]+value;
            else
            {
                triangle[i][j]= max(triangle[i-1][j-1],triangle[i-1][j])+value;
            }
        }
    }
    cout<<*max_element(triangle[size], triangle[size]+size);
    return 0;
}