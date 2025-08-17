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
    // Recursive approach - most intuitive and clean
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: both nodes are null
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If one is null and other is not, they're different
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // If values are different, trees are different
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Alternative iterative approach using stack
class Solution_Iterative {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.push({p, q});
        
        while (!stk.empty()) {
            auto [node1, node2] = stk.top();
            stk.pop();
            
            // Both null - continue
            if (!node1 && !node2) {
                continue;
            }
            
            // One null, other not - different trees
            if (!node1 || !node2) {
                return false;
            }
            
            // Different values - different trees
            if (node1->val != node2->val) {
                return false;
            }
            
            // Add children to stack for comparison
            stk.push({node1->left, node2->left});
            stk.push({node1->right, node2->right});
        }
        
        return true;
    }
};

// Alternative using queue (level-order traversal)
class Solution_BFS {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({p, q});
        
        while (!que.empty()) {
            auto [node1, node2] = que.front();
            que.pop();
            
            if (!node1 && !node2) {
                continue;
            }
            
            if (!node1 || !node2 || node1->val != node2->val) {
                return false;
            }
            
            que.push({node1->left, node2->left});
            que.push({node1->right, node2->right});
        }
        
        return true;
    }
};