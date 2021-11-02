#include <iostream>
using namespace std;

template <class datatype>
class Node
{
public:
    Node();
    Node(datatype item);
    Node(datatype item, Node<datatype> *next);

    datatype getItem() const;
    Node<datatype> *getNext() const;

    void setItem(const datatype item);
    void setNext(const Node<datatype> *next);

    friend ostream &operator<<(ostream &out, const Node &n);

private:
    datatype Item;
    Node<datatype> *Next;
};

template <class datatype>
class LinkedList
{
public:
private:
};