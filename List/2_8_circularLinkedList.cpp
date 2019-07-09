/*
 * < Cracking The Coding Interview 6/E >
 * Problem #2.8 Find the first value of Circular linked list
 * 
 * Author: YeEun Ko
 * 
 */
#include "list.h"
#include <list>
#include<map>
#include<utility>
#include<vector>
#include<algorithm>

using namespace myList;
using namespace std;

myList::SingleLinkedListNode* getFirstNode(myList::CircularLinkedList* clList, int nSize);

int main()
{
    /* Using Library */
    // std::list<char> ls;
    // ls.push_back('A');
    // ls.push_back('B');
    // ls.push_back('C');
    // ls.push_back('D');
    // ls.push_back('E');
    // ls.push_back('C');

    /* without Library */
    myList::CircularLinkedList* clList = new myList::CircularLinkedList();
    clList->insert_node(1);
    clList->insert_node(2);
    clList->insert_node(3);
    clList->insert_node(4);
    clList->insert_node(5);
    clList->insert_node(3);

    clList->print_node(6);
    
    cout<<"\n";
    cout<<"first node: "<<getFirstNode(clList, 6)->nData;

    return 0;
}

myList::SingleLinkedListNode* getFirstNode(myList::CircularLinkedList* clList, int nSize)
{
    int i=0;
    vector<myList::data> pivot;
    myList::SingleLinkedListNode* current=clList->head;

    for(i=0; i<nSize; i++)
    {
        if(find(pivot.begin(), pivot.end(), current->nData)!=pivot.end())
        {
            
            return current;
        }
        
        pivot.push_back(current->nData);
        current=current->next;
        
    }
    return nullptr;
}