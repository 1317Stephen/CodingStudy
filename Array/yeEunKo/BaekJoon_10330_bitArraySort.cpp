/*
 * < BaekJoon >
 * Problem 10330. Reorganize bit Vector.
 *      With or without Library.
 * Author: YeEun Ko
 * 
 */
#include<iostream>
#include<vector>
#include<bitset>
#include<string.h>

using namespace std;

/* Make bitVector: vector<int> -> bit vector */
// return bool* bit vector
bool* bitVectorZero(vector<int>data, int nSize);
bool* bitVectorOne(vector<int>data, int nSize);
// return integer bit vector
int makeBitVector(vector<int>data, int nSize);  //start with 1


/* Print decimal(integer) bit vector */
int decimalToBinary(int numb);
const char *byte_to_binary(int x);

int main()
{
    vector<int>input;
    vector<int>data={1, 3, 2};

    makeBitVector(data, 6);

    return 0;
}
void getSimilarBitVector(bool* input, vector<int>output, int nSize)
{
    int countTrue0=0, countTrue1=0;
    bool* bitVector0 = bitVectorZero(output, nSize);
    bool* bitVector1 = bitVectorOne(output, nSize);

    while(nSize>0)
    {
        bitVector0[nSize-1] = (bitVector0[nSize-1]==input[nSize-1])?true:false;
        bitVector1[nSize-1] = (bitVector1[nSize-1]==input[nSize-1])?true:false;

        if(bitVector0[nSize-1])
        {
            countTrue0++;
        }
        if(bitVector1[nSize-1])
        {
            countTrue1++;
        }
        nSize--;
    }
    
    
}
int makeBitVector(vector<int>data, int nSize)
{
    int i,j;
    int index=0;
    int bitVector=0;

    while(data[index]>0  && nSize>0)
    {
        if(index%2==0)
        {
            bitVector |= 1<<(nSize-1);
        }
        data[index]--;
        nSize--;

        if(data[index]==0)  
        {
            index++;
        }
    }
      
    return bitVector;
}

bool* bitVectorZero(vector<int>data, int nSize)
{
    int i;
    int index=0, iData=0;
    bool*bitVector;
    bitVector=(bool*)malloc(sizeof(bool)*nSize);
    
    while(index<nSize)
    {
        for(i=0; i<data[iData]; i++)
        {
            bitVector[index]=iData%2;
            index++;
        }
        iData++;
    }
    return bitVector;
}
bool* bitVectorOne(vector<int>data, int nSize)
{
    bool* bitVector = bitVectorZero(data, nSize);
    while(nSize>0)
    {
        bitVector[nSize-1] = !bitVector[nSize-1];
        nSize--;
    }
    return bitVector;
}

const char *byte_to_binary(int x, int nSize)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }
    return b;
}

int decimalToBinary(int numb)
{
    int i;
    int result=0;
    for(i=1; numb>0; i*=10)
    {
        int binary = numb%2;
        result+=binary*i;
        numb/=2;
    }
    return result;
}