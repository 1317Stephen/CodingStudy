#include<iostream>
#define T int
class StackNode
{
    public:
        T data;
        StackNode *next;
        StackNode(T data)
        {
            this->data = data;
            this->next=nullptr;
        }   
};
class MyStack
{
    public:
        StackNode *top;
        MyStack()
        {

        }
        void push(StackNode *node)
        {
            if(this->top==nullptr)
            {
                this->top=node;
            }
            else
            {
                
            }
            
        }
};