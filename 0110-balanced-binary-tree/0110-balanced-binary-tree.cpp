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
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
    
private:
    // Returns height if balanced, -1 if not balanced
    int checkBalance(TreeNode* node) {
        if (!node) return 0;
        
        // Check left subtree
        int leftHeight = checkBalance(node->left);
        if (leftHeight == -1) return -1;  // Left subtree is not balanced
        
        // Check right subtree
        int rightHeight = checkBalance(node->right);
        if (rightHeight == -1) return -1;  // Right subtree is not balanced
        
        // Check if current node is balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;  // Current node is not balanced
        }
        
        // Return height of current node
        return max(leftHeight, rightHeight) + 1;
    }
};

/*
Time Complexity: O(n) where n is the number of nodes
Space Complexity: O(h) where h is the height of the tree (recursion stack)

Algorithm Explanation:
1. Use a helper function that returns height if balanced, -1 if not balanced
2. For each node, recursively check left and right subtrees
3. If either subtree is unbalanced, immediately return -1
4. If height difference > 1, return -1 (unbalanced)
5. Otherwise, return the height of the current subtree

Example walkthrough:
- Tree [3,9,20,null,null,15,7]:
  - Node 9: height 1 (leaf)
  - Node 15: height 1 (leaf)  
  - Node 7: height 1 (leaf)
  - Node 20: height 2, balanced (|1-1| = 0 ≤ 1)
  - Node 3: height 3, balanced (|1-2| = 1 ≤ 1)
  - Result: true

- Tree [1,2,2,3,3,null,null,4,4]:
  - Deep left path creates height imbalance
  - When we reach node with height difference > 1, return -1
  - Result: false
*/