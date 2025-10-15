class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        // If left and right exist, connect them
        if (root->left) {
            root->left->next = root->right;
        }

        // If next exists, connect right child of current node
        // to left child of next node
        if (root->right && root->next) {
            root->right->next = root->next->left;
        }

        // Recurse for left and right subtrees
        connect(root->left);
        connect(root->right);

        return root;
    }
};
