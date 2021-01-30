// O(n•logn) time, O(n) space
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res = INT_MAX, min_n = INT_MAX;
        priority_queue<int> pq;
        
        for(int n: nums) {
            n = n % 2 ? n * 2 : n;
            pq.push(n);
            min_n = min(min_n, n);
        }
        
        while(pq.top() % 2 == 0) {
            res = min(res, pq.top() - min_n);
            min_n = min(min_n, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(res, pq.top()-min_n);
    }
};

/*

We can perform 2 operations: halve even numbers and double odd numbers. We can try to sort all numbers, and increase the smallest number (if it's odd),
and decrease the largest number (if it's even) to get minimum deviation, but that'd be complicated.

Intuition:
• We can divide even numbers multiple times - till they become odd, but we can double odd number only once, since it becomes even
• Even numbers can never increase

Flip:
• We can double all odd numbers first, to stop worrying about increasing numbers (second intuititon). 
• Now we only need to worry about, decreasing the largest number - while it's even

Solution:
Double all odd numbers and put all numbers into a max heap. Track the smallest number. Track the minimum difference between the top of the heap and the smallest number. 
While the top of the heap is even, remove it, divide, and put back to the heap.

*/
