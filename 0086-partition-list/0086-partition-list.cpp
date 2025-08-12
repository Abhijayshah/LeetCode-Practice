/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Create two dummy nodes on the stack to act as heads for the two new lists.
        // 'before_head' will lead the list of nodes with values less than x.
        // 'after_head' will lead the list of nodes with values greater than or equal to x.
        ListNode before_head(0);
        ListNode after_head(0);

        // Create tail pointers for each list to allow for O(1) appends.
        ListNode* before_curr = &before_head;
        ListNode* after_curr = &after_head;

        // Iterate through the original linked list.
        while (head != nullptr) {
            // If the current node's value is less than x...
            if (head->val < x) {
                // ...append it to the 'before' list.
                before_curr->next = head;
                before_curr = before_curr->next;
            } else {
                // ...otherwise, append it to the 'after' list.
                after_curr->next = head;
                after_curr = after_curr->next;
            }
            // Move to the next node in the original list.
            head = head->next;
        }

        // After iterating, the 'after' list's tail might still point somewhere
        // in the original list. We must terminate it to prevent cycles.
        after_curr->next = nullptr;

        // Connect the 'before' list with the 'after' list. The tail of the 'before'
        // list should point to the first actual node of the 'after' list.
        before_curr->next = after_head.next;

        // The head of the fully partitioned list is the node right after our dummy 'before_head'.
        return before_head.next;
    }
};