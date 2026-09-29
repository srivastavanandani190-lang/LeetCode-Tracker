class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while(start <= end) {
            // Using start + (end - start) / 2 is safer to prevent potential integer overflow
            mid = start + (end - start) / 2;
            
            if(nums[mid] == target) {
                return mid; // Return the index directly instead of printing
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return -1; // Return -1 if the target is not found
    }
};