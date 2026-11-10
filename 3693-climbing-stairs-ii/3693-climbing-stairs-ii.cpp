class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // dp[j] stores the minimum cost to reach step j.
        // We use 0-indexed costs vector adjusted for 1-based indexing in logic,
        // or we can pad the costs vector to match 1-based indexing easily.
        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;
        
        for (int j = 1; j <= n; ++j) {
            // Check all valid previous steps: j - 1, j - 2, j - 3
            for (int i = max(0, j - 3); i < j; ++i) {
                long long jump_cost = costs[j - 1] + (1LL * (j - i) * (j - i));
                dp[j] = min(dp[j], dp[i] + jump_cost);
            }
        }
        
        return dp[n];
    }
};