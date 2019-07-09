#include <iostream>

namespace myList
{
    typedef int data;
    
    class SingleLinkedListNode
    {
        public:
            data nData;
            SingleLinkedListNode *next;
            SingleLinkedListNode(data nData)
            {
                this->nData=nData;
                this->next=nullptr;
            }
    };
    class SingleLinkedList
    {
        public:
            SingleLinkedListNode *head;
            SingleLinkedListNode *tail;

            SingleLinkedList() 
            {
                this->head = nullptr;
                this->tail = nullptr;
            }
            int total_node_numbers()
            {
                int countNode=0;
                SingleLinkedListNode *current=head;
                while(current)
                {
                    countNode++;
                    current=current->next;
                }
                return countNode;
            }

            void insert_node(int node_data) 
            {
                SingleLinkedListNode* node = new SingleLinkedListNode(node_data);

                if (!this->head) 
                {
                    this->head = node;
                } 
                else 
                {
                    this->tail->next = node;
                }

                this->tail = node;
            }
            void print_node()
            {
                SingleLinkedListNode *node=this->head;
                while(node)
                {
                    std::cout<<node->nData<<" ";
                    node=node->next;
                }
            }
    };
    class CircularLinkedList
    {
        public:
            SingleLinkedListNode *head;
            SingleLinkedListNode *tail;
            CircularLinkedList()
            {
                this->head=nullptr;
                this->tail=nullptr;
                // this->head->next=tail;
            }
            void insert_node(data nData)
            {
                SingleLinkedListNode *node =new SingleLinkedListNode(nData);
                if(!this->head)
                {
                    this->head=node;
                }
                else
                {
                    this->tail->next=node;
                }
                this->tail=node;
                this->tail->next=head;
                
            }
            void print_node(int nSize)
            {
                int i=0;
                SingleLinkedListNode *current=this->head;
                for(i=0; i<nSize; i++)
                {
                    std::cout<<current->nData<<" ";
                    current=current->next;
                }
                std::cout<<"\n";
            }
    };
}