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

  currNode->left = addNode(left, midpoint);
  if (needle != nullptr && needle->data < currNode->data) {
    needle->right = currNode;
    needle = nullptr;
  }
  currNode->right = addNode(midpoint, right);
  if (needle != nullptr && needle->data < currNode->data) {
    needle->right = currNode;
    needle = nullptr;
  }
  if (currNode->right == nullptr && currNode->data < this->getNumberOfNodes())
    currNode->rightThread = true;

  if (currNode->rightThread) {
    needle = currNode;
  }
  return currNode;
}

ostream &operator<<(ostream &out, const ThreadedBST &tBST) {
  tBST.threadedPrint(tBST.root);
  // tBST.inOrderPrint(tBST.root);
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

TNode *ThreadedBST::getLeftNode(TNode *node) const {
  if (node == nullptr)
    return node;
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}

void ThreadedBST::threadedPrint(TNode *root) const {
  if (root == nullptr)
    return;
  TNode *curr = getLeftNode(root);

  while (curr != nullptr) {
    cout << curr->data;
    cout << " ";
    if (curr->rightThread) {
      curr = curr->right;
    } else {
      curr = getLeftNode(curr->right);
    }
  }
}

/**
 * @brief Verify this traversal works!
 *
 * @param node
 * @return TNode*
 */
void ThreadedBST::threadedTraverse(TNode *&node) {
  if (root == nullptr)
    return;
  TNode *curr = getLeftNode(root);
  TNode *temp;
  while (curr != nullptr) {
    cout << curr->data;
    cout << " ";
    if (curr->rightThread) {

      temp = curr->right;
      delete curr;
      curr = temp;
    } else {
      curr = getLeftNode(curr->right);
    }
  }
}

ThreadedBST::~ThreadedBST() { threadedTraverse(root); }

void ThreadedBST::destructorHelper(TNode *&node) {

  if (node->left != nullptr)
    destructorHelper(node->left);
  if (node->right != nullptr)
    destructorHelper(node->right);
  delete node;
}
