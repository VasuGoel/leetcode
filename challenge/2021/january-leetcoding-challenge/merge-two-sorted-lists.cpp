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

// Iterative solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret = nullptr, **pp = &ret;
        
        while(l1 and l2) {
            if(l1->val <= l2->val) {
                *pp = l1;
                l1 = l1->next;
            }
            else {
                *pp = l2;
                l2 = l2->next;
            }
            pp = &((*pp)->next);
        }
        *pp = !l1 ? l2 : l1;
        return ret;
    }
};


// --------------------------------------------------------------------------------------------–


// Recursive solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 or !l2)  return !l1 ? l2 : l1;
        
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
