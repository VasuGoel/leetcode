// O(sqrt(candies)) time, O(num_people) space. Distribute candies until you can't.
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ret (num_people);
        
        for(int i = 0; candies > 0; i++) {
            ret[i % num_people] += min(candies, i+1);
            candies -= i+1;
        }
        return ret;
    }
};
