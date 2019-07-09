/*
 * < Cracking The Coding Interview 6/E >
 * Problem #2.4 Divide the list by pivot
 * 
 * Author: YeEun Ko
 * 
 */

#include"list.h"
#include<iostream>
#include<list>
using namespace myList;
using namespace std;

int main()
{
    /* Using library */
    std::list<int> libList;
    libList.push_back(3);
    libList.push_back(5);
    libList.push_back(8);
    libList.push_back(5);
    libList.push_back(10);
    libList.push_back(2);
    libList.push_back(1);
    for(auto&node: libList)
    {
        cout<< node<<" ";
    }
    cout<<"\n";
    libList.sort();
    for(auto&node: libList)
    {
        cout<< node<<" ";
    }
    cout<<"\n";


    /* Not using library */
    int division=0;
    myList::SingleLinkedList *list = new myList::SingleLinkedList();
    
    list->insert_node(3);
    list->insert_node(5);
    list->insert_node(8);
    list->insert_node(5);
    list->insert_node(10);
    list->insert_node(2);
    list->insert_node(1);

    list->print_node();

    cin>>division;


    return 0;
}

void listDivide(myList::SingleLinkedList *list, int division)
{
    int index=0, countSmall=0;
    bool *largeSmall;
    myList::SingleLinkedListNode *current=list->head;
    largeSmall = (bool*)malloc(sizeof(bool)*list->total_node_numbers() );

    while(current)
    {
        if(current->nData < division)
        {
            largeSmall[index]=false;
            countSmall++;
        }
        else
        {
            largeSmall[index]=true;
        }
        index++;
        current=current->next;
    }
    current=list->head;
    
}
