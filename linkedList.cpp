#include <iostream>
#include "linkedList.h"
using namespace std;

/* Node implementation */
template <class TTT>
Node<TTT>::Node(TTT item) : Item{item}, Next{nullptr} {};

/* Getters*/
template <class TTT>
Node<TTT> *Node<TTT>::getNext() const
{
    return this->Next;
}

template <class TTT>
TTT Node<TTT>::getItem() const
{
    return this->Item;
}

/* Setters*/
template <class TTT>
void Node<TTT>::setNext(const Node<TTT> *next)
{
    this->Next = next;
}
template <class TTT>
void Node<TTT>::setItem(const TTT item)
{
    this->Item = item;
}
/* END of  Node implementation */

// ******************************************************//

/* START of Linked List implementation */

template <class TTT>
LinkedList<TTT>::LinkedList()
{
    Head = nullptr;
}
template <class TTT>
LinkedList<TTT>::LinkedList(TTT &item)
{
    Node<TTT> newNode(item);
    Head = &newNode;
}

template <class TTT>
LinkedList<TTT>::LinkedList(LinkedList<TTT> &copyList)
{
}

// template <class datatype>
// LinkedList<datatype>::~LinkedList()
// {
//     delete Head;
//     Head = nullptr;
// }

template <class TTT>
bool LinkedList<TTT>::add(TTT &item)
{
    Node<TTT> newN = new Node<TTT>;
    Node<TTT> *curr = Head;
    while (curr->getNext() != nullptr)
    {
        curr = curr->getNext();
    }
    return false;
}

template <class TTT>
bool LinkedList<TTT>::remove()
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
