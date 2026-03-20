class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum1 = 0, sum2 = 0;
        
        for(int i = 0; i < gas.size(); i++){
            sum1 += gas[i];
        }
        for(int i = 0; i < cost.size(); i++){
            sum2 += cost[i];
        }

        int count = 0, index = 0;

        if(sum1 < sum2) return -1;
        else{
            for(int i = 0; i < gas.size(); i++){
                count += gas[i] - cost[i];

                if(count < 0){
                    count = 0;
                    index = i + 1;    
                }
            }
        }
        return index;
    }
};