/*
 * <BaekJoon>
 * Problem #1158 Josephus problem
 *      https://www.acmicpc.net/problem/1158
 * 
 * Author: YeEun Ko
 * 
 */
#include "list.h"
#include<iostream>

using namespace myList;
using namespace std;
int main()
{
    int i,j;
    int person, kth;
    myList::CircularLinkedList *ls = new CircularLinkedList();
    myList::SingleLinkedListNode *current, *deleteNode;

    cin>>person;
    cin>>kth;
    // cout<<"person: "<<person<<" kth: "<<kth<<"\n";
    for(i=1; i<=person; i++)
    {
        ls->insert_node(i);
    }
    // cout<<"print ";
    //ls->print_node(person);

    cout<<"<"; 
    current=ls->head;
    while(person>0)
    {
        // current=ls->head;
        for(j=0; j<kth-1; j++)
        {
            current=current->next;
        }
        deleteNode = current;
        
        cout<<current->nData;
        if(person>1)cout<<", ";
        current=current->next;
        // cout<<"next:"<<current->nData<<"\n";
        ls->delete_node(deleteNode->nData);
        // ls->print_node(person);
        person--;

    }
    cout<<">";
    
    
    return 0;
}