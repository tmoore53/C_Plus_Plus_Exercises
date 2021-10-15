/**
 * @file node.h
 * @author Tyler Moore
 * @brief Header file for node
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifdef NODE_
#define NODE_
template <class ChosenType>
class Node()
{
private:
    ChosenType Item;
    Node<ChosenType> *Next;

public:
    Node(){};
    Node(ChosenType item){};

    ~Node(){};

    void setItem(const ChosenType &item) {}
    void setNext(ChosenType * &nextPtr)
        ChosenType
        getItem() const {};
    Node<ChosenType> *getNext() const
}
#include "node.cpp"
#endif