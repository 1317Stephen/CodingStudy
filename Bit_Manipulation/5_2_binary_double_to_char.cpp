#include<iostream>
#include<math.h>
#include<bitset>
using namespace std;
double binaryDoubleToChar(double input);
int main()
{
    cout<<binaryDoubleToChar(0.7);
    //1.4 -> 0.1
    //0.8  > 0.10
    //1.6  > 0.101
    //1.2  > 0.1011

    return 0;
}
double binaryDoubleToChar(double input)
{
    int index=1;
    double binary=0;
    double mask;
    while(index<32)
    {
        input*=2;
        if(index==1 && input<1)mask=input;
        if(index==1 && input>1)mask=input-1;

        if(input>=1)
        {
            binary+=pow(10,-1*index);
            input-=1;
        }
        
        //cout<<input<<" " << mask<<" "<<mask-input<<"\n";
        if(index>1 && abs(mask-input)<pow(10,-10) )
        {
            break;
        }
        if(input-(int)input==0)
        {
            break;
        }
        
        index++;
        
    }
    if(index==32)
    {
        cout<<"ERROR";
        return 0;
    }
    return binary;
}