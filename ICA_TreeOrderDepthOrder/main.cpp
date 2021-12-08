#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * @brief  Leet code challenge 102
 * @tmoore53
 * 
 * https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/ 
 * 
 * 
 * 
 */

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // Create the return vector
        vector<vector<int>> result;
        // If the root was a null pointer then return a empty vector
        if (root == nullptr)
        {
            return result;
        }
        // current nodes on the same level
        queue<TreeNode *> currentNodes;
        //push the root onto current node queue
        currentNodes.push(root);
        // traverse the current nodes in the queue to add their
        // children to the next nodes to be traversed
        while (!currentNodes.empty())
        {
            // New queue that add children nodes
            queue<TreeNode *> nextNodes;
            // Vector that will contain all the children nodes on the
            // same level
            vector<int> thisLevel;
            // traverse the current level of nodes in the queue of
            // current nodes on this level
            while (!currentNodes.empty())
            {
                // Point ot the first node in the queue
                auto curr = currentNodes.front();
                // remove it from the queue
                currentNodes.pop();
                // Add the value to the vector containing the nodes on the sam elevel
                thisLevel.push_back(curr->val);
                // Check left
                if (curr->left != nullptr)
                {
                    // Add the next node to be checked in the queue
                    nextNodes.push(curr->left);
                }
                // Check right
                if (curr->right != nullptr)
                {
                    // Add the next node to be checked in the queue
                    nextNodes.push(curr->right);
                }
            }
            // Once all the nodes on the same level are added, add the
            // vector to the return vector
            result.push_back(thisLevel);
            // Set the current queue of nodes on the same level to the
            // next nodes on the same level
            currentNodes = nextNodes;
        }
        return result;
    };
};
int main()
{

    return 0;
}
