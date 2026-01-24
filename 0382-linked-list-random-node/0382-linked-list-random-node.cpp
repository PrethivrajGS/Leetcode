/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
private:
    ListNode* head;

public:
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int res = 0;
        int i = 1;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (rand() % i == 0) {
                res = curr->val;
            }
            i++;
            curr = curr->next;
        }
        return res;
    }
};
