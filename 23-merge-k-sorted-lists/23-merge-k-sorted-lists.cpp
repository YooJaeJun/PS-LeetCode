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
     ListNode* mergeKLists(vector<ListNode*>& lists) {
         vector<int> forSort;
         for (auto& nodePtr : lists)
         {
             while (nodePtr != nullptr)
             {
                 forSort.push_back(nodePtr->val);
                 nodePtr = nodePtr->next;
             }
         }
         sort(forSort.begin(), forSort.end(), greater<int>());

         ListNode* ans = nullptr;
         for (auto& elem : forSort)
         {
             ans = new ListNode(elem, ans);
         }
         return ans;
     }
 };