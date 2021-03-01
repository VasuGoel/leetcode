// O(n) time and space
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> s (candyType.begin(), candyType.end());
        int variety = s.size();
        return min(variety, n/2);
    }
};
