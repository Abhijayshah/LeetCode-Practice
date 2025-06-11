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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val); // Insert at the correct position
        }
        
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else { // val > root->val (given all values are unique)
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
