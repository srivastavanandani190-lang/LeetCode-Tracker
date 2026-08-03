class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0;
        long long currentSum = 0;
        unordered_map<int, int> countMap;
        
        for (int i = 0; i < n; i++) {
            // Add the current element to the window
            currentSum += nums[i];
            countMap[nums[i]]++;
            
            // If window size exceeds k, remove the element from the left
            if (i >= k) {
                int leftElement = nums[i - k];
                currentSum -= leftElement;
                countMap[leftElement]--;
                if (countMap[leftElement] == 0) {
                    countMap.erase(leftElement);
                }
            }
            
            // If the window size is exactly k, check if all elements are distinct
            if (i >= k - 1) {
                if (countMap.size() == k) {
                    maxSum = max(maxSum, currentSum);
                }
            }
        }
        
        return maxSum;
    }
};