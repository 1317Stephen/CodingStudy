/*
 * < Cracking The Coding Interview 6/E >
 * Problem #1.3 Replace the spaces in a string to "%20"
 * 
 * Author: YeEun Ko
 * 
 */
#include<iostream>
#include<string>

using namespace std;
void replaceSpaces(char *str, int trueLength);

int main()
{
    char str[] = "@! _+|, .!` test < >{ }";
    cout<<str<<"\n";
    replaceSpaces(str, 23);
    cout<<str<<"\n";
    return 0;
}
void replaceSpaces(char *str, int trueLength)
{
    int i=0;
    int fixIndex=0, spaceCount=0;
    for(i=0; i<trueLength; i++)
    {
        if(str[i]==' ')spaceCount++;
    }
    fixIndex = trueLength+spaceCount*2;
    for(i=trueLength-1; i>=0; i--)
    {
        if(str[i]==' ')
        {
            str[fixIndex-1]='0';
            str[fixIndex-2]='2';
            str[fixIndex-3]='%';
            fixIndex-=3;
        }
        else
        {
            str[fixIndex-1]=str[i];
            fixIndex--;
        }
    }

}
