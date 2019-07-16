#include"stack.h"

namespace MyQueue
{
    class Queue
    {
        public:
            MyStack::Stack *stackNew, *stackOld;
            Queue()
            {
                stackNew = new MyStack::Stack();
                stackOld = new MyStack::Stack();
            }
            int size()
            {
                return stackNew->size + stackOld->size;
            }
            void add(int value)
            {
                stackNew->push(value);
            }
            int peek()
            {
                this->shiftStacks();
                return stackOld->peek();
            }
            int remove()
            {
                this->shiftStacks();
                return stackOld->pop();
            }

        private:
            void shiftStacks()
            {
                if(stackOld->isEmpty())
                {
                    while(!stackNew->isEmpty())
                    {
                        stackOld->push(stackNew->pop());
                    }
                }
            }
    };
}