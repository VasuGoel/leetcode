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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr = head, *preptr = nullptr;
        for(int i = 0; i < n; i++) ptr = ptr->next;
        if(ptr == nullptr) {
            head = head->next;
            return head;
        }
        while(ptr != nullptr) {
            ptr = ptr->next;
            if(preptr == nullptr)   preptr = head;
            else    preptr = preptr->next;
        }
        preptr->next = preptr->next->next;
        return head;
    }
};
