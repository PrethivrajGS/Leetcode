/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *n) : val(x), next(n) {}
 * };
 */

class Solution {
public:
    // Function to merge 2 sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = (l1 ? l1 : l2);
        return dummy.next;
    }

    // Function to return middle of the linked list
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // important

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        
        ListNode* mid = getMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        
        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

       
        return merge(leftSorted, rightSorted);
    }
};
