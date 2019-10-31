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

    if(head == nullptr || head->next == nullptr) //case 1: if list is empty - return
    {
        return;
    }

    while(current != nullptr) //exits while loop when the current node reaches the end
    {
        if(current->value > trailer->value) //if current is larger than the previous, we are sorted, and can move forward
        {
            current = current->next; //move forward
            trailer = trailer->next; //move forward
        }
        else
        {
            if(head->value > current-> value) //case 2: if head is larger than the current, we must replace the head with the current
            {
                trailer->next = current->next; //how i did my swap, dont need a temp
                current->next = head;
                head = current;
            }
            else
            {
                sorter = head;
                while((sorter != nullptr) && sorter->next->value < current->value) //case 3: an unsorted number must be placed accurately in the list, this while loop finds the spot
                {
                    sorter = sorter->next;  //moves forward till while loop parameter is incorrect
                }
                trailer->next = current->next; //swaps and inserts once the correct spot is found (while loop does the finding)
                current->next = sorter->next;
                sorter->next = current;
            }
        }
        current = trailer->next; //keeps the trailer right behind current, as current moves forward
    }

}