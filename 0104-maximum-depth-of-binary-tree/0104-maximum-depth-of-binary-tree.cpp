class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: if the node is null, the depth is 0
        if (root == nullptr) {
            return 0;
        }
        
        // Recursively find the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // The maximum depth is the greater of the two depths plus one for the current node
        return 1 + std::max(leftDepth, rightDepth);
    }
};
