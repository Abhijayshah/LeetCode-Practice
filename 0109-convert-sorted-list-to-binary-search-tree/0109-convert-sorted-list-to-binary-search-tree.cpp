/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    TreeNode* sortedListToBST(ListNode* head) {
        // Base case: if the linked list is empty
        if (!head) return nullptr;

        // Base case: if the linked list has only one element
        if (!head->next) return new TreeNode(head->val);

        // Find the middle element of the linked list
        ListNode* mid = findMiddle(head);

        // The middle element becomes the root of the BST
        TreeNode* root = new TreeNode(mid->val);

        // Recursively build the left and right subtrees
        // Disconnect the left half from the middle
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = nullptr; // Disconnect the left half

        root->left = sortedListToBST(leftHead); // Build left subtree
        root->right = sortedListToBST(rightHead); // Build right subtree

        return root;
    }

private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Move fast pointer two steps and slow pointer one step
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // If there is a left half, disconnect it
        if (prev) {
            prev->next = nullptr;
        }

        return slow; // The slow pointer is now at the middle
    }
};
