class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        int index = 0;
        
        for (int i = 0; i < n; i++) {
            ans[index++] = nums[i];     // Insert x_i
            ans[index++] = nums[n + i]; // Insert y_i
        }
        
        return ans;
    }
};