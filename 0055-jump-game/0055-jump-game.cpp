class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // If the current index is greater than the maximum reach, we can't go further
            if (i > maxReach) {
                return false;
            }
            // Update the maximum reach possible from the current position
            maxReach = max(maxReach, i + nums[i]);
            
            // If we can already reach or pass the last index, return true
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }
        return true;
    }
};