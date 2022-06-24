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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 싱글 링크드 리스트
        string sum1;
        while (nullptr != l1)
        {
            sum1 = to_string(l1->val) + sum1;
            l1 = l1->next;
        }
        string sum2;
        while (nullptr != l2)
        {
            sum2 = to_string(l2->val) + sum2;
            l2 = l2->next;
        }

        // string sum
        string result;
        if (sum1.size() > sum2.size()) swap(sum1, sum2);    // sum1 < sum2
        int diff = sum2.size() - sum1.size();
        int carry = 0;  // 받아올림
        for (int i = sum2.size() - 1; i >= 0; i--)
        {
            int sum = carry + sum2[i] - '0';
            if (i - diff >= 0) sum += sum1[i - diff] - '0';
            if (sum >= 10)
            {
                carry = 1;
                sum -= 10;
            }
            else carry = 0;

            result = to_string(sum) + result;
        }
        if (carry == 1) result = '1' + result;

        ListNode* l3 = new ListNode(result[0] - '0');
        int i = 1;

        while (i < result.size())
        {
            ListNode* tmp = l3;
            l3 = new ListNode(result[i] - '0', tmp);
            i++;
        }

        return l3;
    }
};