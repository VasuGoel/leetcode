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

// O(n) time, O(1) space
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head, *prev = dummy;
        
        while(cur) {
            if(cur->val == val)
                prev->next = cur->next;
            else
                prev = cur;
            
            cur = cur->next;
        }
        return dummy->next;
    }
};
