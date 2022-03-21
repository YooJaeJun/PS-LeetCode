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
    ListNode* middleNode(ListNode* head) {
        int idx = 0;
        ListNode head2;
        head2.val = head->val;
        head2.next = head->next;
        while (head2.next != nullptr) {
            idx++;
            head2.val = head2.next->val;
            head2.next = head2.next->next;
        }

        if (idx % 2 == 1) {
            for (int i = 0; i != idx / 2 + 1; i++) {
                head->val = head->next->val;
                head->next = head->next->next;
            }
        }
        else if (idx % 2 == 0) {
            for (int i = 0; i != idx / 2; i++) {
                head->val = head->next->val;
                head->next = head->next->next;
            }
        }

        return head;
    }
};