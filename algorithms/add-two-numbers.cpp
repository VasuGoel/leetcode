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

// O(n) time
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l = nullptr, **pp = &l;
        int sum = 0, carry = 0;
        
        while(l1 or l2 or carry) {
            if(l1)  sum += l1->val, l1 = l1->next;
            if(l2)  sum += l2->val, l2 = l2->next;
            
            *pp = new ListNode(sum % 10);
            pp = &((*pp)->next);
            carry = sum / 10;
            sum = carry;
        }
        return l;
    }
};
