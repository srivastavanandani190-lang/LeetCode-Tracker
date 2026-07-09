class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true; // empty string matches empty pattern

        // Handle patterns like a*, a*b*, a*b*c* matching empty string
        for(int j = 2; j <= m; j++) {
            if(p[j-1] == '*')
                dp[0][j] = dp[0][j-2];
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j-1] == '.' || p[j-1] == s[i-1]) {
                    // current chars match, so check rest
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*') {
                    // 2 cases for *
                    // Case 1: treat * as 0 occurrences of preceding char
                    dp[i][j] = dp[i][j-2];

                    // Case 2: treat * as 1 or more occurrences
                    // if preceding char matches current s char
                    if(p[j-2] == '.' || p[j-2] == s[i-1]) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};