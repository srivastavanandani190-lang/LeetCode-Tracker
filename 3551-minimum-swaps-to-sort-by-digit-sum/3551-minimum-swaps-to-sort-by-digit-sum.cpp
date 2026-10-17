class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> v(n);
        for (int i = 0; i < n; ++i) {
            int sum = 0, temp = nums[i];
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            v[i] = {{sum, nums[i]}, i};
        }
        
        sort(v.begin(), v.end());
        
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i] || v[i].second == i) continue;
            
            int cycle_size = 0;
            int j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = v[j].second;
                cycle_size++;
            }
            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }
};