#include <vector>
#include <numeric>

class Solution {
public:
    // Helper function using your recursive branching logic with memoization
    bool checkSubsetSum(vector<int>& nums, int index, int current_sum, int target, vector<vector<int>>& dp) {
        // Base Cases
        if (current_sum == target) return true; // Found a valid subset sum
        if (index == nums.size() || current_sum > target) return false; // Out of bounds or sum exceeded

        // Return cached result if already computed
        if (dp[index][current_sum] != -1) {
            return dp[index][current_sum];
        }

        // Your 2-choice recursion logic:
        // Choice 1: Exclude current element (pass sum as is)
        // Choice 2: Include current element (add nums[index] to sum)
        bool exclude = checkSubsetSum(nums, index + 1, current_sum, target, dp);
        bool include = checkSubsetSum(nums, index + 1, current_sum + nums[index], target, dp);

        // Store and return result
        return dp[index][current_sum] = (exclude || include);
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // If total sum is odd, we cannot partition into two equal sum subsets
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        // dp table initialized to -1 (dp[index][current_sum])
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        // Start recursion from index 0 with initial sum 0
        return checkSubsetSum(nums, 0, 0, target, dp);
    }
};