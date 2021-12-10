//
// Created by Logan on 11/13/2021.
//

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = nullptr, tail = nullptr;
} // End of constructor

LinkedList::~LinkedList(){

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
        if (id == position->data.id){ // Deleting head node
            if (position == head) {
                head = head->next;
                position->next = nullptr;
                delete position;
                didDelete = true;
            }else if (position->next){ // Deleting middle node
                Node *curr, *prev;
                curr = head;
                while(curr != position){
                    prev = curr;
                    curr = curr->next;
                }
                prev->next = curr->next;
                delete position;
                didDelete = true;
            }else if (position->next == nullptr){ // Deleting tail node
                Node*prev= nullptr;
                Node*curr= head;
                while(curr!=position){
                    prev= curr;
                    curr=curr->next;
                }
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

bool LinkedList::getNode(int id, Node *tempNode){
    Node *position = head;
    bool gotNode = false;
    while (position!= nullptr && !gotNode) {
        std::cout << "inside while loop" << std::endl;
        if(id == position->data.id){
            tempNode = position;
            std::cout << "tempNode = position" << std::endl;
            gotNode = true;
        } else{
            position = position->next;
        }
    }
    return gotNode;
} // End of getNode

void LinkedList::printList(bool backward){
    Node *position = head;
    int loopCount = 1;
    if(!backward && position!= nullptr) {
        while (position != nullptr) {
            std::cout << "Vertex: " << position->data.id;
            if(position->next != nullptr){
                std::cout << " --> ";
//                [EDGE WEIGHT: " << position->edge.weight << "]
            }
            position = position->next;
            loopCount += 1;
        }
    }
} // End of printList

int LinkedList::getCount(){
    int count = 0;
    Node *position = head;
    while(head != nullptr && position != nullptr){
        count++;
        position = position->next;
    }
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
        if(id == position->data.id){
            doesExist = true;
        }
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
    if(head->data.id > newNode->data.id){// new head
        insertHead(newNode);
        didAdd = true;
    }else if(position->data.id > *id) {// Insert middle node
        insertMiddle(position, newNode);
        didAdd = true;
    }else {
        insertTail(position, newNode);// Adds tail node
        didAdd = true;
    }
    return didAdd;
} // End of checkOperation

void LinkedList::insertHead(Node *newNode){
    newNode->next = head;
    head = newNode;
} // End of inserthead

void LinkedList::insertMiddle(Node *position, Node *newNode){
    Node *prev;
    Node *curr = head;
    while(curr != position){
        prev = curr;
        curr = curr->next;
    }
    prev->next = newNode;
    newNode->next = curr;
} // End of insertMiddle

void LinkedList::insertTail(Node *position, Node *newNode){
    position->next = newNode;
    tail = newNode;
    newNode->next = nullptr;
} // End of insertTail