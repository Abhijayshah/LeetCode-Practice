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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if there are at least k nodes left in the list
        ListNode* current = head;
        for (int i = 0; i < k; i++) {
            if (!current) return head; // Not enough nodes
            current = current->next;
        }

        // Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* nextTemp = curr->next; // Store next node
            curr->next = prev; // Reverse the link
            prev = curr; // Move prev to current
            curr = nextTemp; // Move to the next node
        }

        // Now head is the last node in the reversed group
        // Recursively call for the next group and connect
        head->next = reverseKGroup(curr, k);

        // Return the new head of the reversed group
        return prev; // prev is the new head of the reversed group
    }
};
