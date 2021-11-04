#include <iostream>
#include "linkedList.h"
using namespace std;

template <class datatype>
Node<datatype>::Node(datatype item) : Item{item}, Next{nullptr} {};

template <class datatype>
datatype Node<datatype>::getItem() const
{
    return this->Item;
}

template <class datatype>
LinkedList<datatype>::LinkedList()
{
    Head = nullptr;
}
template <class datatype>
LinkedList<datatype>::LinkedList(datatype &item)
{
    Node<datatype> newNode(item);
    Head = &newNode;
}

template <class datatype>
LinkedList<datatype>::LinkedList(LinkedList<datatype> &copyList)
{
}

// template <class datatype>
// LinkedList<datatype>::~LinkedList()
// {
//     delete Head;
//     Head = nullptr;
// }

template <class datatype>
bool LinkedList<datatype>::add(datatype &item)
{
    return false;
}

template <class datatype>
bool LinkedList<datatype>::remove()
{
    return false;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const LinkedList<T> &n)
{
    Node<T> *curr = n.Head;

    return out << "[" << curr->getItem() << "]" << endl;
}
