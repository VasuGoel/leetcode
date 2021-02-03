/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// O(n) time, O(1) space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head, fast = head;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};
