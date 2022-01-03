#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
using namespace std;

template <class TTT>
struct Node
{

public:
    Node();
    Node(TTT item);
    Node(TTT item, Node<TTT> *next);
    //~Node();

    TTT getItem() const;
    Node<TTT> *getNext() const;

    void setItem(const TTT item);

    void setNext(const Node<TTT> *next);

private:
    TTT Item;
    Node<TTT> *Next;
};

template <class TTT>
class LinkedList
{

public:
    //Constructors
    LinkedList();
    LinkedList(TTT &item);
    LinkedList(LinkedList<TTT> &copyList);
    //~LinkedList();

    template <class T>
    friend std::ostream &operator<<(std::ostream &out, const LinkedList<T> &n);

    bool add(TTT &item);
    bool remove();

private:
    Node<TTT> *Head;
};
#endif
