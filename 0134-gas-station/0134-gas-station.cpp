class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum1 = 0, sum2 = 0;
        
        for(int i = 0; i < gas.size(); i++){
            sum1 += gas[i];
            sum2 += cost[i];
        }

        if(sum1 < sum2) return -1;

        int tank = 0;
        int index = 0;

        for(int i = 0; i < gas.size(); i++){
            tank += gas[i] - cost[i];

            if(tank < 0){
                tank = 0;
                index = i + 1;
            }
        }

        return index;
    }
};