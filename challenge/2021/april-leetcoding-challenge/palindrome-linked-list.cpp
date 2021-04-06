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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l1 = head, *l2 = reverseList(slow);
        
        while(l1 and l2) {
            if(l1->val != l2->val)  return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }
    
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = head, *prev = nullptr, *next;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
