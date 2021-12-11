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
  if (currNode->left != nullptr)
    currNode->left->parent = currNode;
  if (needle != nullptr && needle->data < currNode->data) {
    needle->right = currNode;
    needle = nullptr;
  }
  currNode->right = addNode(midpoint, right);
  if (currNode->right != nullptr)
    currNode->right->parent = currNode;
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
    if (curr->rightThread ||
        (curr->right != nullptr && curr->left == nullptr)) {
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
void ThreadedBST::threadedTraverse() {
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
      temp = nullptr;
    } else {
      curr = getLeftNode(curr->right);
    }
  }
}

/**
 * @brief
 *
 * Fix this
 *
 * Failing at curr = 17
 *
 * setting the parent nodes need to be fixed
 * @param node
 */
void ThreadedBST::removeEvens(TNode *node) {
  // Go all the way left

  // Check if the root is null or even and if it is delete and return null

  if (node == nullptr) {
    return;
  }

  TNode *temp;
  TNode *curr = getLeftNode(node);

  if (curr->data % 2 == 0) {
    temp = curr;
    curr = curr->right;
    if (temp->parent != nullptr) {
      // curr->parent->left = temp->parent;
      if (temp->parent == curr->right) {
        if (temp->parent->parent->right == temp->parent)
          temp->parent->parent->right = curr->parent->parent;

        if (temp->parent->parent->left == temp->parent)
          temp->parent->parent->left = curr->parent->parent;
        curr->parent = temp->parent;
      }
    }

    curr->left = nullptr;
    delete temp;
    temp = nullptr;
  }

  while (curr->right != nullptr) {
    temp = curr->right;

    if (curr->right->data % 2 == 0 &&
        (curr->rightThread || curr->left == nullptr)) {
      if (curr->parent == curr->right) {
        if (curr->parent->parent->left == curr->right)
          // This one works in the begining and not at 17
          curr->parent->parent->left = curr;
        if (curr->parent->parent->right == curr->right)
          curr->parent->parent->right = curr;

        // curr->right->right->parent = curr;
      }
      bool transfer = temp->rightThread && temp != root;
      if (curr->right != nullptr)
        curr->rightThread = transfer;

      if (curr->left != nullptr)
        curr->left = curr->left->left;
      curr->right = curr->right->right;
      if (temp == root) {
        curr->right = getLeftNode(root->right);
        root->right->parent = root->left;
        root = root->left;
        root->parent = nullptr;
      }
      curr = curr->right;

      delete temp;
      temp = nullptr;
    }

    else if (curr->right->data % 2 != 0 && curr->right != root) {
      curr = getLeftNode(curr->right);
      removeEvens(curr);
      break;
    } else {
      curr = getLeftNode(curr->right);
      if (curr->data % 2 == 0)
        removeEvens(curr);
      break;
    }
    if (curr == nullptr)
      break;
  }
}

TNode *ThreadedBST::getRoot() { return root; }

ThreadedBST::~ThreadedBST() { threadedTraverse(); }

void ThreadedBST::destructorHelper(TNode *&node) {

  if (node->left != nullptr)
    destructorHelper(node->left);
  if (node->right != nullptr)
    destructorHelper(node->right);
  delete node;
  node = nullptr;
}
