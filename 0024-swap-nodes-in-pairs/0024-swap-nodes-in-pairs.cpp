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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (prev->next && prev->next->next) {
            ListNode* curr = prev->next;
            ListNode* next = curr->next;
            
            // Swapping logic
            curr->next = next->next;
            next->next = curr;
            prev->next = next;
            
            // Move prev to the next position for upcoming swap
            prev = curr;
        }
        
        return dummy.next;
    }
};