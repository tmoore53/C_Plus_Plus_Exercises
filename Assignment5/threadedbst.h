/**
 * @file threadedBST.h
 * @author Tyler Moore (tmoore53@uw.edu)
 * @brief Threaded Binary Search Tree Design File
 * @version 0.1
 * @date 2021-11-28
 * 
 */
#ifndef ASS5_THREADEDBST_H
#define ASS5_THREADEDBST_H

class ThreadedBST;

class TNode
{
    friend class ThreadedBST;

private:
    /* data */
    int data{0};
    TNode *left = nullptr;
    TNode *right = nullptr;

public:
    TNode(int num);
    ~TNode();

    int getData() const;
};

class ThreadedBST
{
    // Display the tree in order
    friend ostream &operator<<(ostream &out, const ThreadedBST &tBST);

private:
    /* data */
    int height{0};
    TNode *root = nullptr;

    // Returns the root data
    int getRootData() const;
    // Retreaves Tree Node desired
    TNode *getTargretNode(const int &nodeData) const;
    // Retreaves the left node pointer's inorder predecessor
    TNode *getInorderPredecessor(const int &nodeData) const;
    // Retreaves the right node pointer's inorder successor
    TNode *getInorderSuccessor(const int &nodeData) const;

public:
    /**
 * @brief Construct a new Threaded B.S.T. object
 * 
 * @param Integer data 
 */
    ThreadedBST(int data);
    /**
     * @brief Destroy the Threaded B.S.T. object
     * 
     */
    ~ThreadedBST();

    // Checks if binary tree is empty
    boolean isEmpty() const;
    // Gets the height of the binary tree
    int getHeight() const;
    // Gets the number of nodes contained in the binary tree
    int getNumberOfNodes() const;

    // Adds data to binary tree
    boolean add(const int newData);
    // Removes data from binary tree
    boolean remove(const int remData);
    // Checks if the value is in the tree
    boolean contains(const int targetData) const;
};

#endif