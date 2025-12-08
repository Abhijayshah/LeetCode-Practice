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

    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> result;

        // Base case: no tree possible → return {NULL}
        if(start > end) {
            result.push_back(nullptr);
            return result;
        }

        // Try each value as root
        for(int i = start; i <= end; i++) {
            
            // All possible left and right subtrees
            vector<TreeNode*> leftTrees = build(start, i - 1);
            vector<TreeNode*> rightTrees = build(i + 1, end);

            // Combine left and right subtrees with root = i
            for(auto left : leftTrees) {
                for(auto right : rightTrees) {

                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;

                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return build(1, n);
    }
};
