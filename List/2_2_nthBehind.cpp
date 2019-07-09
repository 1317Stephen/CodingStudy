/*
 * < Cracking The Coding Interview 6/E >
 * Problem #2.2 Find the nth behind element of Single linked list;
 * 
 * Author: YeEun Ko
 * 
 */
#include "list.h"
#include<iostream>
#include<map>
#include<list>

using namespace std;
using namespace myList;


//Solution #1: get n-th behind node by entire number
myList::SingleLinkedListNode* nthBehindNode(myList::SingleLinkedList *list, int nthBehind);

//Solution #2: in Book- sol#3. iterative way(use two pointer)
std::list<int>::iterator getNthBehindIter(std::list<int> ls, int nthBehind);

int main()
{
    /* Without Library  */
    myList::SingleLinkedList *list = new myList::SingleLinkedList();

    list->insert_node(1);
    list->insert_node(2);
    list->insert_node(3);
    list->insert_node(4);
    list->insert_node(5);
    list->print_node();  
    cout<<"\n";  
    cout<<list->total_node_numbers();
    cout<<"\n";  
    cout<<"behind 2: "<<nthBehindNode(list, 2)->nData<<"\n";
    cout<<"behind 2: "<<nthBehindNode(list, 5)->nData<<"\n";

    /* With Library */
    std::list<int> ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    cout<< *getNthBehindIter(ls, 2);
    return 0;
}
std::list<int>::iterator getNthBehindIter(std::list<int> ls, int nthBehind)
{
    int result=0;
    std::list<int>::iterator frontIt;
    std::list<int>::iterator behindIt;
    frontIt = ls.begin();
    behindIt= ls.begin();
    std::advance(behindIt, nthBehind);

    while(behindIt!=ls.end())
    {
        frontIt++;
        behindIt++;   
    }

    return frontIt;
}


myList::SingleLinkedListNode* nthBehindNode(myList::SingleLinkedList *list, int nthBehind)
{
    SingleLinkedListNode* node=list->head;
    if(nthBehind > list->total_node_numbers())
    {
        return nullptr;
    }
    while(list->total_node_numbers()-nthBehind > 0)
    {
        node=node->next;
        nthBehind++;
    }
    return node;
}
