class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());  // sort prices
        
        int count = 0;
        
        for (int cost : costs) {
            if (coins >= cost) {
                coins -= cost;
                count++;
            } else {
                break;
            }
        }
        
        return count;
    }
};