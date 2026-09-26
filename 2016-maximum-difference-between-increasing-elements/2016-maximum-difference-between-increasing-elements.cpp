class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1;
        
        // Create a vector to store the maximum element from the right (suffix)
        vector<int> max_suffix(n);
        max_suffix[n - 1] = nums[n - 1];
        
        // Fill the max_suffix vector from right to left
        for (int i = n - 2; i >= 0; --i) {
            max_suffix[i] = max(max_suffix[i + 1], nums[i]);
        }
        
        int max_diff = -1;
        
        // Iterate through the array to find the maximum difference
        for (int i = 0; i < n - 1; ++i) {
            // We only calculate difference if the right maximum is strictly greater
            if (nums[i] < max_suffix[i + 1]) {
                max_diff = max(max_diff, max_suffix[i + 1] - nums[i]);
            }
        }
        
        return max_diff;
    }
};