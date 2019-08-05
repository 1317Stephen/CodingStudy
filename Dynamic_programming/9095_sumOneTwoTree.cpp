/*********************************
 * BaekJoon #9095. 1, 2, 3 더하기
 * Author: YeEun Ko
 * https://www.acmicpc.net/problem/9095
 *
 ************ 문제 ************
 정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
    1+1+1+1
    1+1+2
    1+2+1
    2+1+1
    2+2
    1+3
    3+1
    정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
 *********************************/
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