class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Skip the next node (duplicate)
                current->next = current->next->next;
            } else {
                // Move to the next unique node
                current = current->next;
            }
        }
        
        return head;
    }
};
