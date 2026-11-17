#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        
        // divisors[len] stores all proper divisors of len (excluding len itself)
        vector<vector<int>> divisors(n + 1);
        for (int len = 1; len <= n; ++len) {
            for (int d = 1; d < len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                }
            }
        }
        
        // cost[i][j] = min changes to make substring s[i...j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                // Try all proper divisors d of the current substring length
                for (int d : divisors[len]) {
                    int current_cost = 0;
                    // Check each of the d groups
                    for (int g = 0; g < d; ++g) {
                        int left = i + g;
                        int right = j - (d - 1 - g); // corresponding end of the interleaved group
                        while (left < right) {
                            if (s[left] != s[right]) {
                                current_cost++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], current_cost);
                }
            }
        }
        
        // dp[i][parts] = min changes to partition s[i...n-1] into 'parts' semi-palindromes
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        
        for (int parts = 1; parts <= k; ++parts) {
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    // We need at least enough remaining characters for the remaining parts
                    if (j - i + 1 >= 2 && n - 1 - j >= k - parts) {
                        dp[j + 1][parts] = min(dp[j + 1][parts], dp[i][parts - 1] + cost[i][j]);
                    }
                }
            }
        }
        
        // Find the minimum cost to partition the entire string into k parts
        int ans = 1e9;
        for (int i = 0; i < n; ++i) {
            if (n - 1 - i >= k - 1) {
                // Combine dp[0][k-1] up to i and cost[i][n-1]
                // Wait, let's look at the partition DP correctly:
            }
        }
        
        // Standard tabulation DP approach for partition:
        // dp[i][p] represents partitioning s[0...i] into p parts.
        vector<vector<int>> memo(n, vector<int>(k + 1, -1));
        auto solve = [&](auto& self, int idx, int rem_k) -> int {
            if (idx == n) return rem_k == 0 ? 0 : 1e9;
            if (rem_k == 0) return 1e9;
            if (memo[idx][rem_k] != -1) return memo[idx][rem_k];
            
            int res = 1e9;
            // Try ending the current partition at index j
            for (int j = idx; j < n; ++j) {
                int len = j - idx + 1;
                if (len >= 2) {
                    res = min(res, cost[idx][j] + self(self, j + 1, rem_k - 1));
                }
            }
            return memo[idx][rem_k] = res;
        };
        
        return solve(solve, 0, k);
    }
};