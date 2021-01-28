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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)   return head;
        int n = 0;
        for(auto it = head; it; it = it->next)  n++;
        k %= n;
        if(!k)  return head;
        
        auto it = head;
        for(int i = 0; i < n-k-1; i++)    it = it->next;
        
        auto ret = it->next, end = ret;
        it->next = nullptr;
        for(end; end->next; end = end->next);
        end->next = head;
        return ret;
    }
};
