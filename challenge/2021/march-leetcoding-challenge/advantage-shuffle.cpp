// O(n•logn) time, O(n) space. Greedy approach - pick least A[i] which is greater than B[i], otherwise put smallest A[i] at B[i]
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s (A.begin(), A.end());
        
        for(int i = 0; i < A.size(); i++) {
            auto it = *s.rbegin() <= B[i] ? s.begin() : s.upper_bound(B[i]);
            A[i] = *it;
            s.erase(it);
        }
        return A;
    }
};
