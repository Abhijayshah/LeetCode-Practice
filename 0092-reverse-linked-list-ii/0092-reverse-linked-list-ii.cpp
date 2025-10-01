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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node to handle edge cases
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        // Step 1: Move prev to node just before "left"
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse sublist from left to right
        ListNode* curr = prev->next;
        ListNode* nextNode = nullptr;
        ListNode* prevNode = nullptr;

        for (int i = 0; i <= right - left; i++) {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }

        // Step 3: Reconnect sublist
        prev->next->next = curr; // connect tail of reversed sublist to rest
        prev->next = prevNode;   // connect prev part to head of reversed sublist

        return dummy->next;
    }
};
