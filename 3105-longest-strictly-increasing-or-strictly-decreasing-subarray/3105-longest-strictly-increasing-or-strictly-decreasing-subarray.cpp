class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxLen = 1;
        int incLen = 1;
        int decLen = 1;
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] > nums[i]) {
                incLen++;
                decLen = 1; // reset decreasing length
            } else if (nums[i + 1] < nums[i]) {
                decLen++;
                incLen = 1; // reset increasing length
            } else {
                incLen = 1;
                decLen = 1;
            }
            maxLen = max({maxLen, incLen, decLen});
        }
        
        return maxLen;
    }
};