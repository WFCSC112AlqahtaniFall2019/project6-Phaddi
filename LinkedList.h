//
// Created by Ryan Phadnis on 10/24/19.
//

#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList {
public:
    LinkedList(); //default constructor

    LinkedList(const LinkedList &list); //constructor

    ~LinkedList(); //destructor

    //functs
    bool isItem(int item) const;

    void append(int item);

    bool remove(int item);

    LinkedList &operator=(const LinkedList &rhs);

    void printList() const;

    void InsertionSort();

private:
    Node *head = new Node;
};

#endif //BINARYINSERTIONSORT_LINKEDLIST_H
