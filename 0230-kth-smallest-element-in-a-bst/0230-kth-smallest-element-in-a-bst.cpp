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
    int count = 0; // To keep track of the number of nodes visited
    int result = 0; // To store the kth smallest value

    void inOrderTraversal(TreeNode* node, int k) {
        if (!node) return; // Base case: if the node is null, return

        // Traverse the left subtree
        inOrderTraversal(node->left, k);
        
        // Visit the current node
        count++;
        if (count == k) {
            result = node->val; // Store the kth smallest value
            return; // No need to continue once we found the kth smallest
        }

        // Traverse the right subtree
        inOrderTraversal(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inOrderTraversal(root, k); // Start in-order traversal
        return result; // Return the kth smallest value
    }
};
