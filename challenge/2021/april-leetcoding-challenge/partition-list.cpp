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
    ListNode* partition(ListNode* head, int x) {
        ListNode *ret = nullptr, **pp = &ret;   // head of final list to return
        
        // add a dummy node to start of main list
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head, *pre = dummy;
        
        while(cur != nullptr) {
            // if cur node value is smaller than x, put it into new list and remove it from main list
            if(cur->val < x) {
                *pp = cur;
                pp = &((*pp)->next);
                pre->next = cur->next;
            } 
            else    pre = cur;      // else skip this node in main list
            
            cur = cur->next;
        }
        
        *pp = dummy->next;      // lastly append remaining main list (having values greater than or equal to x), to 'ret' list (having values smaller than x)
        return ret;
    }
};
