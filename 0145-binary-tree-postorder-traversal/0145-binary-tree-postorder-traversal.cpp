class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }

private:
    void traverse(TreeNode* node, vector<int>& res) {
        if (!node) return;
        traverse(node->left, res);
        traverse(node->right, res);
        res.push_back(node->val);
    }
};
