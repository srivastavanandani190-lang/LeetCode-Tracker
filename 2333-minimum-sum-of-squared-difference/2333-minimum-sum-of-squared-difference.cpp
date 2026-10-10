class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalOps = (long long)k1 + k2;
        
        // Find maximum difference to size our frequency array
        int maxDiff = 0;
        vector<long long> diffCount(100005, 0);
        long long initialDiffSum = 0;
        
        for (int i = 0; i < n; ++i) {
            int d = abs(nums1[i] - nums2[i]);
            diffCount[d]++;
            initialDiffSum += d;
        }
        
        // If total operations are enough to reduce all differences to 0
        if (initialDiffSum <= totalOps) {
            return 0;
        }
        
        // Greedily reduce from the largest differences downwards
        for (int d = 100000; d > 0 && totalOps > 0; --d) {
            if (diffCount[d] == 0) continue;
            
            long long take = min(diffCount[d], totalOps);
            diffCount[d] -= take;
            diffCount[d - 1] += take;
            totalOps -= take;
        }
        
        // Calculate the final minimum sum of squared differences
        long long result = 0;
        for (int d = 1; d <= 100000; ++d) {
            if (diffCount[d] > 0) {
                result += diffCount[d] * (long long)d * d;
            }
        }
        
        return result;
    }
};