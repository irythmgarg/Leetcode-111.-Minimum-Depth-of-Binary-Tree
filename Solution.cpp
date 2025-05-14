/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    /**
     * Recursive helper function to determine the minimum depth.
     *
     * @param root - Current node being visited.
     * @param value - Reference to the smallest depth encountered so far.
     * @param level - Current depth level of traversal.
     */
    void findmindepth(TreeNode* root, int &value, int level) {
        if (!root) return;  // Base case: null node

        // If leaf node is reached, update minimum depth
        if (!root->left && !root->right) {
            value = min(value, level);
            return;
        }

        // Recursively explore left and right subtrees
        findmindepth(root->left, value, level + 1);
        findmindepth(root->right, value, level + 1);
    }

    /**
     * Computes the minimum depth of a binary tree.
     * A leaf is defined as a node with no children.
     *
     * @param root - Root node of the binary tree.
     * @return int - Minimum depth from root to the nearest leaf node.
     */
    int minDepth(TreeNode* root) {
        int value = INT_MAX;

        // Edge case: empty tree
        if (!root) return 0;

        // Start recursive depth calculation
        findmindepth(root, value, 1);
        return value;
    }
};
