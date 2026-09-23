class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int target = total_sum - x;
        
        // If the total sum is exactly x, we must remove all elements
        if (target == 0) return nums.size();
        // If the total sum is less than x, it's impossible
        if (target < 0) return -1;
        
        int n = nums.size();
        int max_len = -1;
        int current_sum = 0;
        int left = 0;
        
        // Sliding window to find the longest subarray with sum == target
        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];
            
            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }
            
            if (current_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        return max_len == -1 ? -1 : n - max_len;
    }
};