// intlist.cpp
// Implements class IntList
// Oviya Seeniraj 2/5/23

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList &source)
{
    Node *n = this->first;
    Node *og = source.first;
    while (og != nullptr)
    {
        n->info = og->info;
        n = n->next;
        og = og->next;
    }
}

// destructor deletes all nodes
IntList::~IntList()
{
    while (this->first != nullptr)
    {
        Node *n = this->first;
        this->first = this->first->next;
        delete n;
    }
}

// return sum of values in list
int IntList::sum() const
{
    int sum = 0;
    Node *n = this->first;
    while (n != nullptr)
    {
        sum = sum + n->info;
        n = n->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const
{
    Node *n = this->first;
    while (n != nullptr)
    {
        if (n->info == value)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const
{
    if (this->first == nullptr)
    {
        return 0;
    }
    int max = this->first->info;
    Node *n = this->first;
    while (n != nullptr)
    {
        if (n->info > max)
        {
            max = n->info;
        }
        n = n->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const
{
    if (this->first == nullptr)
    {
        return 0;
    }
    double sum = 0;
    double numNodes = 0;
    Node *n = this->first;
    while (n != nullptr)
    {
        sum = sum + n->info;
        numNodes++;

        n = n->next;
    }
    return (sum / numNodes);
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value)
{
    Node *n = new Node;
    n->info = value;
    n->next = this->first;
    this->first = n;
}

// Assignment operator should copy the list from the source
// to this list, deleting/replacing any existing nodes
IntList &IntList::operator=(const IntList &source)
{
    while (this->first != nullptr)
    {
        Node *n = this->first;
        this->first = this->first->next;
        delete n;
    }

    Node *copyFrom = source.first;
    Node *n = this->first;

    while (copyFrom != nullptr)
    {
        n->info = copyFrom->info;
        n = n->next;
        copyFrom = copyFrom->next;
    }
    return *this;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) {}

// append value at end of list
void IntList::append(int value)
{
    if (first == 0)
    { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else
    {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const
{
    Node *n = first;
    cout << '[';
    while (n)
    {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const
{
    int result = 0;
    Node *n = first;
    while (n)
    {
        ++result;
        n = n->next;
    }
    return result;
}
