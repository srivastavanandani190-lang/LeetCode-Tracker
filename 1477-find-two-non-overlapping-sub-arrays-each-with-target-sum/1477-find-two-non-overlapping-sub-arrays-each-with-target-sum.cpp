class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // best[i] stores the minimum length of a valid sub-array ending at or before index i
        vector<int> best(n, INT_MAX); 
        
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        int min_len = INT_MAX;
        
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            // Shrink window if the sum exceeds the target
            while (sum > target && left <= right) {
                sum -= arr[left++];
            }
            
            if (sum == target) {
                int len = right - left + 1;
                
                // If there's a valid non-overlapping sub-array before the current one
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }
                
                // Track the minimum sub-array length found so far
                min_len = min(min_len, len);
            }
            
            // Update the DP array for the current index
            best[right] = min_len;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};