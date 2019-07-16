/*
 * < Cracking The Coding Interview 6/E >
 * Problem #3.2 Find the min value of the stack.
 *          Time Complexity of push, pop, min should be O(1),
 * 
 * Author: YeEun Ko
 * 
 */
#include "stack.h"
#include<iostream>
#include<stack>
using namespace MyStack;
using namespace std;

int main()
{
    MyStack::StackWithMin *s = new MyStack::StackWithMin();
    s->push(3);
    s->push(2);
    s->push(5);
    
    cout<<"size: "<<s->size<<"\n";
    cout<<"min: "<<s->min();
    
    return 0;
}
