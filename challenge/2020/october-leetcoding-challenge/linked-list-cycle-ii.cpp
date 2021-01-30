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
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;

        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                auto ret = head;
                while(ret != slow) {
                    ret = ret->next;
                    slow = slow->next;
                }
                return ret;
            }
        }
        return nullptr;
    }
};

/*

• Let L1 be distance between the head point and entry point
• Let L2 be distance between the entry point and the meeting point

Distance traveled by slow when they meet: L1+L2
Distance traveled by fast when they meet: L1+L2+x+L2, where x is the remaining length of the cycle (meeting point to start of the cycle).

2(L1+L2) = L1+L2+x+L2
2L1 + 2L2 = L1+2L2+x
=> x = L1

So we need to move L1 steps from the current meeting point to reach the entry point of the cycle.

*/
