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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0); // Start DFS with initial sum as 0
    }
    
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0; // Base case: if the node is null, return 0
        
        // Update the current sum by appending the current node's value
        currentSum = currentSum * 10 + node->val;
        
        // If it's a leaf node, return the current sum
        if (!node->left && !node->right) {
            return currentSum;
        }
        
        // Recursively calculate the sum for left and right subtrees
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};
