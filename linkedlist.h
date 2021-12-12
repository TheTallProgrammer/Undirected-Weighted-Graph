/*********************
Name: Logan Falkenberg
Final Project
Purpose: Contains the prototype attributes/methods to manipulate a singly linked list.
**********************/

#ifndef SIMPLE_LINKED_LIST_LINKEDLIST_H
#define SIMPLE_LINKED_LIST_LINKEDLIST_H

#include "data.h"
#include <iostream>

class LinkedList{

public:

    // Constructor/Destructor
    LinkedList();
    ~LinkedList();

    //Methods
    bool addNode(int, string*, int);
    bool deleteNode(int);
    Node * getNode(int);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);
    bool getTail(Data *);

private:

    // Pointer to the first node
    Node *head, *tail;

    // Private methods
    void initializeNode(int *, string*, Node*, int *);
    bool checkOperation(Node *, Node *, int *);
    void insertTail(Node *, Node *);

}; // End of class LinkedList

#endif //SIMPLE_LINKED_LIST_LINKEDLIST_H
