/*
 * < Cracking The Coding Interview 6/E >
 * Problem #3.4 Implement Queue with two Stacks
 * 
 * Author: YeEun Ko
 * 
 */
#include"queue.h"
#include<iostream>
using namespace MyQueue;
using namespace std;
int main()
{
    MyQueue::Queue *q=new MyQueue::Queue();
    q->add(3);
    q->add(2);
    q->add(5);
    cout<<q->peek();
    return 0;
}
