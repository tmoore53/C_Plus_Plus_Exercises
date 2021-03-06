/**
 * @file threadedBST.h
 * @author Tyler Moore (tmoore53@uw.edu) @tmoore53
 * @brief Threaded Binary Search Tree Design File
 * @version 0.1
 * @date 2021-11-28
 * 
 * Compile and run with bash ./simplecompile.sh > output.txt 2>&1
 *
 */
#ifndef ASS5_THREADEDBST_H
#define ASS5_THREADEDBST_H
#include <iostream>
using namespace std;

class ThreadedBST;

class TNode {
  friend class ThreadedBST;

private:
  /* data */
  int data{0};
  // Data less than this data
  TNode *left = nullptr;
  // Data greater than this date
  TNode *right = nullptr;
  // Identifies if a node is a leaf
  bool rightThread = false;
  // Identifies parent
  TNode *parent = nullptr;

public:
  TNode(int num);
  ~TNode();

  int getData() const;
};

class ThreadedBST {
  // Display the tree in order traversal with right threads
  friend ostream &operator<<(ostream &out, const ThreadedBST &tBST);

private:
  /* data */
  int height{0};
  int numberOfNodes;
  TNode *root = nullptr;
  TNode *needle = nullptr;
  // Returns the lowest node value
  TNode *findRightThread(TNode *&leftestNode);

  // Retreaves Tree Node desired
  TNode *getTargretNode(const int &nodeData) const;
  // Retreaves the right node pointer's inorder successor
  TNode *getInorderSuccessor(const int &nodeData) const;
  // Helper method to insert new nodes
  TNode *addNode(int left, int right);
  // Helper method that enables traversal though the tree
  void destructorHelper(TNode *&node);
  // Helper method to enable traversing through the tree in order
  void inOrderPrint(TNode *node) const;
  // Helper method to print tree that is threaded
  void threadedPrint(TNode *root) const;
  // Helper method to get the most left node from the starting node
  TNode *getLeftNode(TNode *node) const;
  // Create a threaded traversal method
  void threadedTraverse();

  int *returnBSTVal(const ThreadedBST &tree);

public:
  /**
   * @brief Construct a new Threaded B.S.T. object
   *
   * The constructor of will use cin implementation to set the amount of
   * nodes into the threaded binary search tree.
   *
   * @param Integer data specifying the number of nodes to create in your
   * tree
   */
  ThreadedBST();

  /**
   * @brief Destroy the Threaded B.S.T. object
   *
   */
  ~ThreadedBST();

  TNode *getRoot();

  // Checks if binary tree is empty

  bool isEmpty() const;
  // Gets the height of the binary tree
  int getHeight() const;
  // Gets the number of nodes contained in the binary tree
  int getNumberOfNodes() const;

  // Remove all even numbers
  void removeEvens(TNode *root);

  // Checks if the value is in the tree
  bool contains(const int &targetData) const;

  /**
   * @brief "=" operator overload to make a deep
   * copy of a threaded binary search trees
   *
   */
  ThreadedBST &operator=(const ThreadedBST &original);

  // The following 2 methods don't need to be implemented
  // // Adds data to binary tree
  // boolean add(const int newData);
  // // Removes data from binary tree
  // boolean remove(const int remData);
};
#endif

/**
 * @brief
 *     if (curr->right->data % 2 != 0 && curr->rightThread) {
      curr = curr->right;
    }
    if (curr != root && curr->left != nullptr)
      removeEvens(curr);

 *
 */