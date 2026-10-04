class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        
        while (s < e) {
            int mid = s + (e - s) / 2;
            
            // If the current element is greater than the next one, 
            // we are on a descending slope. A peak must exist to the left (including mid).
            if (nums[mid] > nums[mid + 1]) {
                e = mid;
            } 
            // If the current element is smaller than the next one,
            // we are on an ascending slope. A peak must exist to the right of mid.
            else {
                s = mid + 1;
            }
        }
        
        // When s == e, we have narrowed down to a single peak element.
        return s;
    }
};