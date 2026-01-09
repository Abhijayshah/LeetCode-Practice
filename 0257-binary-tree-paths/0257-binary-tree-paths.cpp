class Solution {
public:
    
    void dfs(TreeNode* node, string path, vector<string>& result) {
        
        if (node == nullptr) return;              // Base case

        // Add current node value to path
        path += to_string(node->val);

        // If leaf node, store the path
        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(path);
            return;
        }

        path += "->";                             // Add arrow before recursion

        dfs(node->left, path, result);            // Go left
        dfs(node->right, path, result);           // Go right
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> result;                    // Stores all paths

        if (root == nullptr) return result;       // Edge case

        dfs(root, "", result);                    // Start DFS
        return result;                            // Return all paths
    }
};
