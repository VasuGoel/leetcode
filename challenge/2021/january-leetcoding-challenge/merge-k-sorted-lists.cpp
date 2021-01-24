/**
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// O(n•logn) time, O(n) space
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [&](auto a, auto b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);
        
        for(auto &list: lists)
            if(list)    pq.push(list);
        
        ListNode *l = nullptr, **pp = &l;
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if(cur->next)   pq.push(cur->next);
            
            cur->next = nullptr;
            *pp = cur;
            pp = &((*pp)->next);
        }
        return l;
    }
};
