#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    class SlidingWindowMedianCost {
        int x;
        priority_queue<long long> low; // max heap for lower half
        priority_queue<long long, vector<long long>, greater<long long>> high; // min heap for upper half
        unordered_map<long long, int> delayed_low, delayed_high;
        int size_low = 0, size_high = 0;
        long long sum_low = 0, sum_high = 0;

        void prune_low() {
            while (!low.empty() && delayed_low[low.top()] > 0) {
                delayed_low[low.top()]--;
                low.pop();
            }
        }

        void prune_high() {
            while (!high.empty() && delayed_high[high.top()] > 0) {
                delayed_high[high.top()]--;
                high.pop();
            }
        }

        void balance() {
            prune_low();
            prune_high();
            int target_low = (x + 1) / 2;

            while (size_low > target_low) {
                prune_low();
                if (low.empty()) break;
                long long val = low.top();
                low.pop();
                sum_low -= val;
                size_low--;
                high.push(val);
                sum_high += val;
                size_high++;
                prune_low();
            }

            while (size_low < target_low && !high.empty()) {
                prune_high();
                if (high.empty()) break;
                long long val = high.top();
                high.pop();
                sum_high -= val;
                size_high--;
                low.push(val);
                sum_low += val;
                size_low++;
                prune_high();
            }
        }

    public:
        SlidingWindowMedianCost(int window_size) : x(window_size) {}

        void add(long long num) {
            prune_low();
            if (low.empty() || num <= low.top()) {
                low.push(num);
                sum_low += num;
                size_low++;
            } else {
                high.push(num);
                sum_high += num;
                size_high++;
            }
            balance();
        }

        void remove(long long num) {
            prune_low();
            prune_high();
            if (!low.empty() && num <= low.top()) {
                delayed_low[num]++;
                sum_low -= num;
                size_low--;
            } else {
                delayed_high[num]++;
                sum_high -= num;
                size_high--;
            }
            balance();
        }

        long long get_cost() {
            prune_low();
            if (low.empty()) return 0;
            long long median = low.top();
            return (median * size_low - sum_low) + (sum_high - median * size_high);
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> costs(n - x + 1, 0);

        SlidingWindowMedianCost sw(x);
        for (int i = 0; i < x; ++i) {
            sw.add(nums[i]);
        }
        costs[0] = sw.get_cost();

        for (int i = x; i < n; ++i) {
            sw.remove(nums[i - x]);
            sw.add(nums[i]);
            costs[i - x + 1] = sw.get_cost();
        }

        const long long INF = 1e18;
        vector<long long> prev_dp(n + 1, 0);
        vector<long long> curr_dp(n + 1, INF);

        for (int j = 1; j <= k; ++j) {
            fill(curr_dp.begin(), curr_dp.end(), INF);
            long long min_prev = INF;
            
            for (int i = 1; i <= n; ++i) {
                if (i >= x) {
                    min_prev = min(min_prev, prev_dp[i - x]);
                }
                if (min_prev != INF) {
                    curr_dp[i] = min_prev + costs[i - x];
                }
                curr_dp[i] = min(curr_dp[i], curr_dp[i - 1]);
            }
            prev_dp = curr_dp;
        }

        return prev_dp[n];
    }
};