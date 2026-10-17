class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long MOD = 1e9 + 7;
        
   
        vector<long long> sum(4 * n, 0);
        vector<long long> sumSq(4 * n, 0);
        vector<long long> lazy(4 * n, 0);
        
        auto apply = [&](int node, int l, int r, long long val) {
          
            sumSq[node] = (sumSq[node] + 2 * val * sum[node] + val * val * (r - l + 1)) % MOD;
            sum[node] = (sum[node] + val * (r - l + 1)) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
        };
        
        auto push = [&](int node, int l, int r) {
            if (lazy[node] != 0) {
                int mid = (l + r) / 2;
                apply(2 * node, l, mid, lazy[node]);
                apply(2 * node + 1, mid + 1, r, lazy[node]);
                lazy[node] = 0;
            }
        };
        
        auto update = [&](auto& self, int node, int l, int r, int ql, int qr, long long val) -> void {
            if (ql > r || qr < l) return;
            if (ql <= l && r <= qr) {
                apply(node, l, r, val);
                return;
            }
            push(node, l, r);
            int mid = (l + r) / 2;
            self(self, 2 * node, l, mid, ql, qr, val);
            self(self, 2 * node + 1, mid + 1, r, ql, qr, val);
            sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
            sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % MOD;
        };
        
        unordered_map<int, int> last_pos;
        long long total_sum = 0;
        
        for (int j = 0; j < n; ++j) {
            int prev = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;
            
            update(update, 1, 0, n - 1, prev + 1, j, 1);
            last_pos[nums[j]] = j;
           
            total_sum = (total_sum + sumSq[1]) % MOD;
        }
        
        return total_sum;
    }
};