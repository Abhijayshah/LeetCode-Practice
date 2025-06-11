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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        // Initialize a dummy node which acts as the starting node of the output list
        ListNode* dummyNode = new ListNode(-1);

        // Tail node starts at the dummy node
        ListNode* tail = dummyNode;

        while (list1 && list2) {
           // Compare the current nodes of both lists, link the smaller one
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            // Move the tail pointer forward to maintain the list
            tail = tail->next;
        }

        // Attach the remaining part of list1 or list2
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;

        // Skip over dummy node to return the actual start of merged list
        ListNode* mergedHead = dummyNode->next;
        delete dummyNode;
        return mergedHead;
    }
};
