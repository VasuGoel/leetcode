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

// O(n) time, O(1) space. One pass.
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *a = nullptr, *b = nullptr;
        for(auto it = head; it ; it = it->next) {
            b = !b ? nullptr : b->next;
            if(!--k) {
                a = it;
                b = head;
            }
        }
        swap(a->val, b->val);
        return head;
    }
};
