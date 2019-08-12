#include<iostream>
#include<bitset>
using namespace std;
int bitInsert(int orgBit, int addBit, int startIndex, int endIndex);
int main()
{
    int a, b;
    a=76, b=6;
    cout<<bitset<8>(a)<<"\n";
    cout<<bitset<4>(b)<<"\n";

    cout<<bitset<8>(bitInsert(a,b,3,5))<<"\n";
    return 0;
}
int bitInsert(int orgBit, int addBit, int startIndex, int endIndex)
{
    int allOnes=~0;
    int left=allOnes<<(endIndex+1);
    int right= ((1<<startIndex)-1);
    int mask=left|right;

    int orgClean=orgBit&mask;
    int addShift=addBit<<startIndex;

    return addShift | orgClean;
}