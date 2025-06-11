class Solution {
public:
    int maxDiameter = 0;

    int height(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // update max diameter at this node
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // return height of current node
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
};
