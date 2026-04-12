class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
        k = k % n; // handle if k > n
        
        // Step 1: Reverse whole array
        reverse(nums.begin(), nums.end());
        
        // Step 2: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: Reverse last n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};