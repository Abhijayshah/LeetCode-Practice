#include <queue>

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true; // An empty tree is symmetric
        
        std::queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            if (!left && !right) continue; // Both nodes are null
            if (!left || !right) return false; // One of the nodes is null
            if (left->val != right->val) return false; // Values are not equal
            
            // Push children in the order that they need to be compared
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        
        return true;
    }
};
