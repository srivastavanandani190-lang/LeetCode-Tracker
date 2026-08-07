class Solution {
public:
    int solve(vector<int>& nums, int index, int target) {
        // Base case: if we have considered all elements
        if (index == nums.size()) {
            return target == 0 ? 1 : 0;
        }
        
        // Choice 1: Subtract current element
        int subtract = solve(nums, index + 1, target - nums[index]);
        
        // Choice 2: Add current element
        int add = solve(nums, index + 1, target + nums[index]);
        
        return subtract + add;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, target);
    }
};