class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int maxSum = 0, currentMax = 0;
        int minSum = 0, currentMin = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            // Find maximum subarray sum
            currentMax += arr[i];
            if (currentMax < 0) currentMax = 0;
            maxSum = max(maxSum, currentMax);
            
            // Find minimum subarray sum
            currentMin += arr[i];
            if (currentMin > 0) currentMin = 0;
            minSum = min(minSum, currentMin);
        }
        
        return max(maxSum, abs(minSum));
    }
};