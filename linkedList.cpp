#include <iostream>
#include "linkedList.h"
using namespace std;

/* Node implementation */
template <class datatype>
Node<datatype>::Node(datatype item) : Item{item}, Next{nullptr} {};

/* Getters*/
template <class datatype>
Node<datatype> *Node<datatype>::getNext() const
{
    return this->Next;
}

template <class datatype>
datatype Node<datatype>::getItem() const
{
    return this->Item;
}

/* Setters*/
template <class datatype>
void Node<datatype>::setNext(const Node<datatype> *next)
{
    this->Next = next;
}
template <class datatype>
void Node<datatype>::setItem(const datatype item)
{
    this->Item = item;
}
/* END of  Node implementation */

// ******************************************************//

/* START of Linked List implementation */

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
    Node<datatype> newN = new Node<datatype>;
    Node<datatype> *curr = Head;
    while (curr->getNext() != nullptr)
    {
        curr = curr->getNext();
    }
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

/* END of Linked List implementation */
