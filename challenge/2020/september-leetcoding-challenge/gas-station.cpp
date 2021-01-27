// O(n) time, O(1) space 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int station = 0, tank = 0, total_gas = 0, total_cost = 0;
        
        for(int i = 0; i < gas.size(); i++) {
            total_gas += gas[i], total_cost += cost[i];
            
            tank += gas[i]- cost[i];
            if(tank < 0) {
                tank = 0;
                station = i+1;
            }
        }
        if(total_gas < total_cost)  return -1;
        return station;
    }
};

/*

Following are 2 simple observations:
• If totalGas >= totalCost, there must be a valid route, return -1 otherwise
• At any station, tank = gas[i] - cost[i], cannot be -ve

So, approach is quite simple, we can keep accumulating total_gas and total_cost to check if total_gas >= total_cost and guarantee there's an answer,
then also keep accumulating tank += gas[i] - cost[i], for every station, if at any point tank < 0, we reset tank = 0
and set 'start' (stores result valid station index) to next station index

*/
