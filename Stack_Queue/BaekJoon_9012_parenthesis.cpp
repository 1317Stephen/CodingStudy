#include <list>

#include <iostream>
using namespace std;

int main()
{
    string ps="";
    int i=0, j=0,index=0, top=0;
    int cases=0;

    cin>>cases;
    for(i=1; i<=cases; i++)
    {
        list<char>stack;
        cin>>ps;
        for(j=0; j<ps.size(); j++)
        {
            if(ps[j]=='(')
            {
                stack.push_back('(');
            }   
            else if(ps[j]==')')
            {
                if(stack.back()=='(')
                {
                    stack.pop_back();
                }
                else
                {
                    stack.push_back(')');
                }
            }
        }
        if(stack.empty())
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        
    }
    return 0;
}

