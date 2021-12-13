/**
 * @file threadedBST.cpp
 * @author Tyler Moore (tmoore53@uw.edu)
 * @brief
 * @version 0.1
 * @date 2021-11-28
 * 
 * Comple and run bash ./simplecompile.sh > output.txt 2>&1
 *
 */

#include "threadedbst.h"
#include <iostream>
#include <queue>
using namespace std;

int TNode::getData() const { return this->data; }
TNode::TNode(int num) { data = num; }

TNode::~TNode(){};

int ThreadedBST::getHeight() const { return this->height; }

/**
 * @brief
 *  Checks if tree is empty
 *
 * @return true
 * @return false
 */
bool ThreadedBST::isEmpty() const {
  if (this->root == nullptr)
    return true;
  return false;
}

/**
 * @brief
 *
 * @return int : number of node initially creating the tree
 */
int ThreadedBST::getNumberOfNodes() const { return this->numberOfNodes; }

/**
 * @brief Construct a new Threaded B S T:: Threaded B S T object
 *
 */
ThreadedBST::ThreadedBST() {
  cout << "Enter the amount of nodes that the banary tree should have." << endl;

  cin >> numberOfNodes;

  cout << "You created a binary search tree that contains "
       << this->getNumberOfNodes() << " nodes" << endl;

  this->root = addNode(0, getNumberOfNodes() + 1);
}

/**
 * @brief
 * Helper method that returns a balanced tree root
 *
 * @param left node
 * @param right node
 * @return TNode* : Roor node is returned
 */
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

/**
 * @brief
 * prints the contents of the tree in order
 *
 * @param out
 * @param tBST
 * @return ostream&
 */
ostream &operator<<(ostream &out, const ThreadedBST &tBST) {
  // tBST.threadedPrint(tBST.root);
  tBST.inOrderPrint(tBST.root);
  return out << "\n";
}

/**
 * @brief Helper method that prints the contents of a tree in order
 *
 * @param node
 */
void ThreadedBST::inOrderPrint(TNode *node) const {
  if (node != nullptr) {
    inOrderPrint(node->left);
    cout << node->data;
    cout << " ";
    if (!node->rightThread)
      inOrderPrint(node->right);
  }
}

/**
 * @brief Returns to lowest valued node
 *
 * Helper metthod
 *
 * @param node
 * @return TNode*
 */
TNode *ThreadedBST::getLeftNode(TNode *node) const {
  if (node == nullptr)
    return node;
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}

/**
 * @brief Helper method that Prints all nodes in the tree
 *
 *  Starts at the lowest node and prints it's successor
 *
 * This has memory leaks
 * @param root
 */
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
 * deletes even numbers from the tree
 *
 *  ------- Should only be ran once per tree ----
 *
 * ------This function does not fully function------
 *
 * Current known limitations are that the tree can's have more
 * than 20 Nodes for this funtion to work
 *
 * setting the parent/right nodes need to be fixed
 * @param node Takes in the root of the tree
 */
void ThreadedBST::removeEvens(TNode *node) {
  // Go all the way left

  // Check if the root is null or even and if it is delete and return null

  if (node == nullptr) {
    return;
  }

  TNode *target;
  TNode *curr = getLeftNode(node);

  if (curr->data % 2 == 0) {
    target = curr;
    curr = curr->right;
    if (curr == nullptr) {
      delete target;
      return;
    }
    if (target->parent != nullptr) {

      // If the node being deleted is also the next value then
      // set the deleting node children to the current
      if (target == curr->right) {
        if (target->parent->parent->right == target->parent)
          target->parent->parent->right = curr->parent->parent;

        if (target->parent->parent->left == target->parent)
          target->parent->parent->left = curr->parent->parent;
        curr->parent = target->parent;
      } else if (target->left == nullptr && target->rightThread &&
                 target->right != curr) {
        curr->right = target->right;
      } else {
        curr->parent = curr->parent->parent;
        if (target == curr->parent->right)
          curr->parent->right = curr;
        if (target == curr->parent->left)
          curr->parent->left = curr;
      }
    }

    curr->left = nullptr;
    delete target;
    target = nullptr;
    this->numberOfNodes--;
  }

  while (curr->right != nullptr) {
    target = curr->right;

    if (target->data % 2 == 0 && (curr->rightThread || curr->left == nullptr)) {

      if (target->parent != nullptr) {
        if (target == curr->parent) {
          curr->parent = target->parent;
          if (curr->data > curr->parent->data) {
            curr->parent->right = curr;
          } else if (curr->data < curr->parent->data) {
            curr->parent->left = curr;
          }
          curr->right = target->right;
          curr->right->parent = curr;
          if (curr != target->left && target->right != nullptr)
            curr->left = target->left;
        } else {
          curr->parent = target->parent;
          if (target->data < target->parent->data) {
            target->parent->left = target->left;
            curr->right = target->right;
          } else if (target->data > target->parent->data) {
            target->parent->right = target->right;
          }

          if (target->left != nullptr) {
            target->left->parent = curr;
            curr->right = target->left;
          }
          if (curr->right != nullptr) {
            curr->right = target->right;
          }
          if (!target->rightThread && target->right != nullptr)
            target->right->parent = curr;
        }
      }
      bool transfer = target->rightThread && target != root;
      if (curr->right != nullptr)
        curr->rightThread = transfer;

      if (curr->left != nullptr && curr->left != nullptr)
        curr->left = curr->left->left;
      if (target == root) {
        curr->right = getLeftNode(root->right);
        root->right->parent = root->left;
        root = root->left;
        root->parent = nullptr;
      }
      curr = curr->right;

      delete target;
      target = nullptr;
      this->numberOfNodes--;
    }

    else if (curr->right->data % 2 != 0 && curr->right != root) {
      // curr = getLeftNode(curr->right);
      removeEvens(curr->right);
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

/**
 * @brief Root getter
 *
 * returns the root node of the tree
 * @return TNode*
 */
TNode *ThreadedBST::getRoot() { return root; }

/**
 * @brief Destroy the Threaded B S T:: Threaded B S T object
 *
 */
ThreadedBST::~ThreadedBST() { destructorHelper(root); }

/**
 * @brief Destructor helper
 *
 * @param node
 */
void ThreadedBST::destructorHelper(TNode *&node) {

  if (node->left != nullptr)
    destructorHelper(node->left);
  if (node->right != nullptr && !node->rightThread)
    destructorHelper(node->right);
  delete node;
  node = nullptr;
}

// /* function to delete element in binary tree */
// TNode *ThreadedBST::deletion(TNode *root, int val) {
//   if (root == nullptr)
//     return nullptr;

//   if (root->left == nullptr && root->right == nullptr) {
//     if (root->data == val)
//       return nullptr;
//     else
//       return root;
//   }

//   queue<TNode *> q;
//   q.push(root);

//   TNode *temp;
//   TNode *key_node = nullptr;

//   // Do level order traversal to find deepest
//   // node(temp) and node to be deleted (key_node)
//   while (!q.empty()) {
//     temp = q.front();
//     q.pop();

//     if (temp->data == val) {
//       key_node = temp;
//       break;
//     }

//     if (temp->left != nullptr)
//       q.push(temp->left);

//     if (temp->right != nullptr && !temp->rightThread)
//       q.push(temp->right);
//   }

//   if (key_node != nullptr) {
//     int x = temp->data;
//     deletDeepest(root, temp);
//     key_node->data = x;
//   }
//   return root;
// }

// void ThreadedBST::copyConstructor(TNode *root, TNode *d_node) {
//   // Temporary queue
//   queue<TNode *> q;
//   // Push the root
//   q.push(root);

//   // Do level order traversal until last node
//   TNode *temp;
//   while (!q.empty()) {
//     temp = q.front();
//     q.pop();
//     if (d_node->data % 2 == 0) {
//       temp = nullptr;
//       delete d_node;
//       return;
//     }
//     if (temp->right != nullptr && !temp->rightThread) {
//       if (d_node->data % 2 == 0) {
//         temp->right = nullptr;
//         delete d_node;
//         return;
//       } else
//         q.push(temp->right);
//     }

//     if (temp->left != nullptr) {
//       if (d_node->data % 2 == 0) {
//         temp->left = nullptr;
//         delete d_node;
//         return;
//       } else
//         q.push(temp->left);
//     }
//   }
// }

// void ThreadedBST::copyConstructor(TNode *root, TNode *d_node) {
//   vector<int> retVec;
//   // Temporary queue
//   queue<TNode *> q;
//   // Push the root
//   q.push(root);

//   // Do level order traversal until last node
//   TNode *temp;
//   while (!q.empty()) {
//     temp = q.front();
//     q.pop();

//     if (temp->left != nullptr) {
//       copyConstructor(temp->left, root);
//       // q.push(temp->left);
//     }

//     if (temp->right != nullptr && !temp->rightThread) {
//       copyConstructor(temp->right, root);

//       // q.push(temp->right);
//     }
//     retVec.push_back(temp->data);
//   }
//   // return retVec;
// }

// ThreadedBST &ThreadedBST::operator=(const ThreadedBST &original) {}
