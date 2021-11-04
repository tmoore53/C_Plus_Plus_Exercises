#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
using namespace std;

template <class datatype>
struct Node
{

public:
    Node();
    Node(datatype item);
    Node(datatype item, Node<datatype> *next);
    //~Node();

    datatype getItem() const;
    Node<datatype> *getNext() const;

    void setItem(const datatype item);

    void setNext(const Node<datatype> *next);

private:
    datatype Item;
    Node<datatype> *Next;
};

template <class datatype>
class LinkedList
{

public:
    //Constructors
    LinkedList();
    LinkedList(datatype &item);
    LinkedList(LinkedList<datatype> &copyList);
    //~LinkedList();

    template <class T>
    friend std::ostream &operator<<(std::ostream &out, const LinkedList<T> &n);

    bool add(datatype &item);
    bool remove();

private:
    Node<datatype> *Head;
};
#endif
