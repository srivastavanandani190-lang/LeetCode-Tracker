class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        
        // 1. Count the occurrences of each card automatically
        for (int card : deck) {
            count[card]++;
        }
        
        // 2. Find the GCD of all the counts
        int res = 0; 
        for (auto& [card, freq] : count) {
            res = gcd(res, freq);   
        }
        
        // 3. If the final GCD is 2 or more, a valid grouping exists
        return res >= 2;
    }
};