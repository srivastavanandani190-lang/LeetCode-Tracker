class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> res;
        
        // Count frequencies of even numbers
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                res[nums[i]]++;
            }
        }
        
        int maxFreq = -1;
        int mostFreqElement = -1;
        
        // Iterate through the map correctly
        for(auto it : res) {
            int currentElement = it.first;
            int currentFreq = it.second;
            
            // Update if we find a higher frequency, 
            // or if frequencies tie but the element is smaller
            if(currentFreq > maxFreq || (currentFreq == maxFreq && currentElement < mostFreqElement)) {
                maxFreq = currentFreq;
                mostFreqElement = currentElement;
            }
        }
        
        return mostFreqElement;
    }
};