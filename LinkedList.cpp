//
// Created by Ryan Phadnis on 10/30/19.
//
#include "LinkedList.h"
#include <iostream>
using namespace std;

//default constructor
LinkedList::LinkedList()
{
    head = nullptr;
}

//copy constructor - creates deep copy
LinkedList::LinkedList(const LinkedList & list)
{
    head = new Node;
    while(head != nullptr)
    {
        append(head->value);
        head = head->next;
    }
}

//destructor
LinkedList::~LinkedList()
{
    delete head;
}

//copy assignment operator
LinkedList &LinkedList::operator=(const LinkedList &rhs)
{
    LinkedList temp(rhs);
    swap(head, temp.head);
    return *this;
}

void LinkedList::append(int item)
{
    if(head == nullptr)
    {
        head = new Node(item);
    }
    else
    {
        Node* current = head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node(item);
    }
}

/* bool LinkedList::remove(int item)
{
    Node* current = head;
    Node* trailer = head;
    //case 1: list is empty
    if(head == nullptr)
    {
        return false;
    }
    //case 2: item is head
    if(head->value == item)
    {
        head = head->next;
        trailer = trailer->next;
        current->next = nullptr;
        delete current;
        return true;
    }
    //case 3: have to run thru list to find item
    while(current != nullptr)
    {
        trailer->next = current->next;
    }
} */
// ^^I spent too long on this for it to not even be useful for this project

void LinkedList::printList() const
{
    Node* current = head;
    if(!current)
    {
        cout << "The list is empty." << endl;
    }
    else
    {
        while(current)
        {
            cout << current->value << " ";
            current = current->next;
        }
    }
    cout << endl;
}

//insertion sort function
void LinkedList::InsertionSort()
{
    Node *current = head->next;
    Node *trailer = head;
    Node *sorter = head;

    if(head == nullptr || head->next == nullptr)
    {
        return;
    }

    while(current != nullptr)
    {
        if(current->value > trailer->value)
        {
            current = current->next;
            trailer = trailer->next;
        }
        else
        {
            if(head->value > current-> value)
            {
                trailer->next = current->next;
                current->next = head;
                head = current;
            }
            else
            {
                sorter = head;
                while((sorter != nullptr) && sorter->next->value < current->value)
                {
                    sorter = sorter->next;
                }
                trailer->next = current->next;
                current->next = sorter->next;
                sorter->next = current;
            }
        }
        current = trailer->next;
    }

}