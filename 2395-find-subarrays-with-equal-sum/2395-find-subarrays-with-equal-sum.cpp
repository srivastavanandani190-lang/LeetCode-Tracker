#include <vector>
#include <unordered_set>

class Solution {
public:
    bool findSubarrays(std::vector<int>& nums) {
        std::unordered_set<int> seen_sums;
        
        // Loop through the array, stopping 1 element before the end
        // so we can always form a length 2 subarray: nums[i] and nums[i+1]
        for (int i = 0; i < nums.size() - 1; i++) {
            int current_sum = nums[i] + nums[i+1];
            
            // If the sum is already in our set, we found a match
            if (seen_sums.count(current_sum)) {
                return true;
            }
            
            // Otherwise, add this sum to the set and keep checking
            seen_sums.insert(current_sum);
        }
        
        return false;
    }
};