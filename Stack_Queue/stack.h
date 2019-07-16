#include<climits>
namespace MyStack
{
    class StackNode
    {
        public:
            int data;
            StackNode *next;
            StackNode(int data)
            {
                this->data=data;
            }
    };
    class Stack
    {
        public:
            int size=0;
            StackNode* top;
            int pop()
            {
                if(this->top==nullptr)
                {
                    return (int)nullptr;
                }
                int item=this->top->data;
                this->top=this->top->next;
                this->size--;
                return item;
            }
            void push(int item)
            {
                StackNode *t = new StackNode(item);
                t->next = this->top;
                this->size++;
                this->top=t;
            }
            int peek()
            {
                if(this->top==nullptr)
                {
                    return (int)nullptr;
                }
                return this->top->data;
            }
            bool isEmpty()
            {
                return this->top==nullptr;
            }
    };
    class StackWithMin : Stack
    {
        public:
            Stack *s2;
            int size;
            StackWithMin()
            {
                this->s2=new Stack();
                this->size=0;
            }
            int min()
            {
                if(this->s2->isEmpty())
                {
                    return INT_MAX;
                }
                else
                {
                    return s2->peek();
                }
            }
            void push(int value)
            {
                if(value<=min())
                {
                    s2->push(value);
                }
                this->size++;
                StackNode *t = new StackNode(value);
                t->next = this->top;
                this->top=t;
            }
            int pop()
            {
                this->size--;
                if(this->top==nullptr)
                {
                    return (int)nullptr;
                }
                int value=this->top->data;
                this->top=this->top->next;

                if(value==min())
                {
                    s2->pop();
                }
                return value;
            }

    };
}
