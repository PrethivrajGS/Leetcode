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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head; // Only one node or empty list — already sorted

        ListNode* dummy = new ListNode(0); // Dummy head for the sorted portion

        while (head) {
            ListNode* nextNode = head->next; // Keep next node
            ListNode* prev = dummy;

            // Find correct insertion position
            while (prev->next && prev->next->val < head->val) {
                prev = prev->next;
            }

            // Insert current node into sorted part
            head->next = prev->next;
            prev->next = head;

            // Move to next node
            head = nextNode;
        }

        return dummy->next;
    }
};
