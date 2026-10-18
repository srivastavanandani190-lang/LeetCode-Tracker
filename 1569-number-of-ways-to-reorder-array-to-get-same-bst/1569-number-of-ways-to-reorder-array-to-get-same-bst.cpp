class Solution {
public:
    int numOfWays(vector<int>& nums) {
        long long mod = 1e9 + 7;
        int n = nums.size();
        
        // Precompute Pascal's triangle for combinations C(n, k)
        vector<vector<long long>> table(n + 1, vector<long long>(n + 1, 1));
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        
        auto dfs = [&](auto& self, const vector<int>& subnums) -> long long {
            int len = subnums.size();
            if (len <= 2) return 1;
            
            vector<int> left, right;
            int root = subnums[0];
            for (int i = 1; i < len; ++i) {
                if (subnums[i] < root) {
                    left.push_back(subnums[i]);
                } else {
                    right.push_back(subnums[i]);
                }
            }
            
            long long leftWays = self(self, left) % mod;
            long long rightWays = self(self, right) % mod;
            
            long long ways = table[len - 1][left.size()];
            ways = (ways * leftWays) % mod;
            ways = (ways * rightWays) % mod;
            
            return ways;
        };
        
        return (dfs(dfs, nums) - 1 + mod) % mod;
    }
};