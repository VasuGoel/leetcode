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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)   return head;
        ListNode *o = head, *e = head->next, *even = e;
        
        while(e and e->next) {
            o->next = o->next->next;
            e->next = e->next->next;
            
            o = o->next;
            e = e->next;
        }
        o->next = even;
        return head;
    }
};
