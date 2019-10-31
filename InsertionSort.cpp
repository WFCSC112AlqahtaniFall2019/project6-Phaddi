//Ryan Phadnis
#include <iostream>
#include <vector>
#include "BinaryInsertionSort.h"
#include "Node.h"
#include <cassert>
#include <ctime>
#include "LinkedList.h"

using namespace std;

int main() {

    cout << "Enter seed, length: " << endl;

    int seed, length;
    cin >> seed >> length;
    srand(seed);
    LinkedList list;
    vector<int> v(length);

    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
    }

    //create the LinkedList
    for(int i = 0; i < v.size(); i++)
    {
        int a = v[i];
        list.append(a);
    }

    cout << "Unsorted LinkedList: " << endl;
    list.printList();

    clock_t begbinary = clock();
    insertionSort(v, v.size());
    clock_t endbinary = clock();

    clock_t beginsertion = clock();
    list.InsertionSort();
    clock_t endinsertion = clock();

    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }

    // print out sorted list (binary)
    cout << "Sorted with Binary: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Sorted with Insertion" << endl;
    list.printList();
    cout << endl;

    double totalbinary;
    totalbinary = double(endbinary - begbinary);
    double totalinsertion;
    totalinsertion = double(endinsertion - beginsertion);

    cout << "Time to Binary Sort: " << totalbinary << endl;
    cout << "Time to Insertion Sort: " << totalinsertion << endl;


    // FINISH ME

}