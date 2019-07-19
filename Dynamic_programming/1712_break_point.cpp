#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int fixed, variable, price;
    double breakEvenPoint;
    cin>>fixed>>variable>>price;
    breakEvenPoint=fixed/(price-variable);
    if(breakEvenPoint==(int)breakEvenPoint)
    {
        cout<<breakEvenPoint+1;
    }
    else
    {
        cout<<ceil(breakEvenPoint);
    }
    return 0;
}