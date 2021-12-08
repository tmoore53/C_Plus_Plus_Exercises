/**
 * @file threadedBST.cpp
 * @author Tyler Moore (tmoore53@uw.edu)
 * @brief
 * @version 0.1
 * @date 2021-11-28
 *
 */

#include "threadedbst.h"
#include <iostream>
using namespace std;

int TNode::getData() const { return this->data; }
TNode::TNode(int num) { data = num; }

TNode::~TNode(){};

int ThreadedBST::getHeight() const { return this->height; }

bool ThreadedBST::isEmpty() const {
  if (this->root == nullptr)
    return true;
  return false;
}

int ThreadedBST::getNumberOfNodes() const { return this->numberOfNodes; }

ThreadedBST::ThreadedBST() {
  cout << "Enter the amount of nodes that the banary tree should have." << endl;

  cin >> numberOfNodes;

  cout << "You created a binary search tree that contains "
       << this->getNumberOfNodes() << " nodes" << endl;

  this->root = addNode(0, getNumberOfNodes() + 1);
}

TNode *ThreadedBST::addNode(int left, int right) {
  if (left + 1 == right)
    return nullptr;
  // set the midpoint
  int midpoint = left + (right - left) / 2;
  // Create a new node with midpoint value
  TNode *currNode = new TNode(midpoint);
  // if the node is the root of the tree set the parent
  if (midpoint == getNumberOfNodes() / 2)
    parentNode = currNode;
  currNode->left = addNode(left, midpoint);
  currNode->right = addNode(midpoint, right);
  if (currNode->right == nullptr && currNode->data < this->getNumberOfNodes())
    currNode->rightThread = true;
  return currNode;
}

ostream &operator<<(ostream &out, const ThreadedBST &tBST) {
  tBST.inOrderPrint(tBST.root);
  return out << "\n";
}

void ThreadedBST::inOrderPrint(TNode *node) const {
  if (node != nullptr) {
    inOrderPrint(node->left);
    cout << node->data;
    cout << " ";
    inOrderPrint(node->right);
  }
}

ThreadedBST::~ThreadedBST() { destructorHelper(root); }

void ThreadedBST::destructorHelper(TNode *&node) {
  if (node->left != nullptr)
    destructorHelper(node->left);
  if (node->right != nullptr)
    destructorHelper(node->right);
  delete node;
}
