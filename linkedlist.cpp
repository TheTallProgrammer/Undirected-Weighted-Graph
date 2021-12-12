/*********************
Name: Logan Falkenberg
Final Project
Purpose: This file contains the methods of class linkedList. Is implemented inside of the graph class.
**********************/

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = nullptr, tail = nullptr;
} // End of constructor

LinkedList::~LinkedList(){
//    clearList();
} // End of destructor

//Methods
bool LinkedList::addNode(int id, string *data, int edgeWeight){
    bool didAdd = false;
    Node *position = head;
    if(id >= 0 && data->length() > 0 ) {
        while ((head != nullptr) && id > position->data.id && position->next != nullptr) {// Loops through the list to find a spot for the node
            position = position->next;
        }if(head != nullptr && id == position->data.id){}
        else if (head == nullptr) {// First head node
            Node *newNode = new Node();
            initializeNode(&id, data, newNode, &edgeWeight);
            head = newNode;
            tail = newNode;
            didAdd = true;
        } else if (head != nullptr){
            Node *newNode = new Node();
            initializeNode(&id, data, newNode, &edgeWeight);
            didAdd = checkOperation(position, newNode, &id);
        }
    }
    return didAdd;
} // End of addNode

bool LinkedList::deleteNode(int id){
    bool didDelete = false;
    Node *position = head;
    while(position!=nullptr && !didDelete){
        if (id == position->data.id){
            if (position == head) { // Deleting head node
                head = head->next;
                position->next = nullptr;
                delete position;
                didDelete = true;
            }if (position->next){ // Deleting middle node
                Node *curr, *prev;
                curr = head;
                while(curr != position){prev = curr; curr = curr->next;}
                prev->next = curr->next;
                delete position;
                didDelete = true;
            }if (position->next == nullptr){ // Deleting tail node
                Node*prev= nullptr;
                Node*curr= head;
                while(curr!=position){prev= curr; curr=curr->next;}
                prev->next= nullptr;
                tail = prev;
                delete position;
                didDelete = true;
            }
        }
        position = position->next;
    }
    return didDelete;
} // End of deleteNode

Node *LinkedList::getNode(int id){
    Node *position = head;
    bool gotNode = false;
    while (position!= nullptr && !gotNode) {
        if(id == position->data.id){
            gotNode = true;
        } else{
            position = position->next;
        }
    }
    return position;
} // End of getNode

void LinkedList::printList(bool backward){
    Node *position = head;
    if(!backward && position!= nullptr) {
        while (position != nullptr) {
            std::cout << position->data.id;
            if(position->next != nullptr){std::cout << " --> (weight: " << position->next->edge.weight << ")";}
            position = position->next;
        }
    }
} // End of printList

int LinkedList::getCount(){
    int count = 0;
    Node *position = head;
    while(head != nullptr && position != nullptr){count++; position = position->next;}
    return count;
} // End of getCount

bool LinkedList::clearList(){
    bool didClear = false;
    Node *position;
    while(head!=nullptr){
        position = head;
        head = head->next;
        delete position;
        didClear = true;
    }
    return didClear;
} // End of clearList

bool LinkedList::exists(int id){
    Node *position = head;
    bool doesExist = false;
    while(position!=nullptr){
        if(id == position->data.id){doesExist = true;}
        position = position->next;
    }
    return doesExist;
} // End of exists

bool LinkedList::getTail(Data *data){
    bool hasTail = false;
    if(tail!= nullptr){
        data->id = tail->data.id;
        data->data = tail->data.data;
        hasTail = true;
    }
    return hasTail;
} // End of getTail


// Private methods
void LinkedList::initializeNode(int *id, string *data, Node *newNode, int *edgeWeight){
    newNode->data.id = *id;
    newNode->data.data = *data;
    newNode->edge.weight = *edgeWeight;
    newNode->next = nullptr;
} // End of initializeNode

bool LinkedList::checkOperation(Node *position, Node *newNode, int *id){
    bool didAdd = false;
    insertTail(position, newNode);// Adds tail node
    didAdd = true;
    return didAdd;
} // End of checkOperation

void LinkedList::insertTail(Node *position, Node *newNode){
    position->next = newNode;
    tail = newNode;
    newNode->next = nullptr;
} // End of insertTail