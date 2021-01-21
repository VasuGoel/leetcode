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
    void reorderList(ListNode* head) {
        if(!head)   return;
        ListNode *slow = head, *fast = head;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l1 = head, *l2 = reverseList(slow->next);
        slow->next = nullptr;
        
        while(l1 and l2) {
            ListNode *a = l1->next, *b = l2->next;
            
            l1->next = l2;
            l2->next = a;
            l1 = a, l2  = b;
        }
    }
    
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = head, *prev = nullptr;
        while(cur) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

/*

Consider list: 1->2->3->4->5

• Split lists midway: 1->2->3 and 4->5
• Reverse second list: 5->4
• Merge second list into first as: 1->5->2->4->3

*/
