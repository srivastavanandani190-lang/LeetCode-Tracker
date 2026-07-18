class Solution {
public:
    int uniquePaths(int m, int n) {
        // We need to calculate (m + n - 2) C (m - 1)
        // To minimize iterations, use the smaller of (m - 1) and (n - 1)
        int totalSteps = m + n - 2;
        int k = min(m - 1, n - 1);
        
        long long res = 1;
        
        for (int i = 1; i <= k; ++i) {
            res = res * (totalSteps - k + i) / i;
        }
        
        return (int)res;
    }
};