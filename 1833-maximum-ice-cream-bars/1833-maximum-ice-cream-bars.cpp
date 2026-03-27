class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = 0;
        
        // Step 1: Find maximum cost
        for (int cost : costs) {
            maxCost = max(maxCost, cost);
        }
        
        // Step 2: Create frequency array
        vector<int> freq(maxCost + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }
        
        int count = 0;
        
        // Step 3: Buy from cheapest to costliest
        for (int price = 1; price <= maxCost; price++) {
            while (freq[price] > 0 && coins >= price) {
                coins -= price;
                freq[price]--;
                count++;
            }
        }
        
        return count;
    }
};