// O(n) time, O(1) space. Greedy approach. 
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // sort costs based on how much more city A costs than city B for each person
        sort(costs.begin(), costs.end(), [&](auto &a, auto &b) -> bool {
            return a[0] - a[1] > b[0] - b[1];
        });

        // pick first n/2 costs for city B and then remaining city A
        int n = costs.size(), c = 0;
        for(int i = 0; i < n; i++) {
            c += (i < n/2) ? costs[i][1] : costs[i][0];
        }
        return c;
    }
};

/*

Given, costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]

Sort based on how much more city A costs than city B, and pick greedily 
first n/2 costs for city B and remaining for city A for min overall costs -

       ------
[840, | 118]
[448, | 54]
[926, | 667]
       ------
-----      
[577 |, 469]
[184 |, 139]
[259 |, 770]
-----

*/
