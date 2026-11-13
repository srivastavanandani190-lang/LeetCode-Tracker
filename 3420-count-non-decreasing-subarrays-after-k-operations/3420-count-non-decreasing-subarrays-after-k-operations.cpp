
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<pair<int, int>> dq;

        long long cost = 0;
        long long ans = 0;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            int count = 1;

            // Merge smaller groups with the current element
            while (!dq.empty() && dq.back().first < nums[i]) {

                int value = dq.back().first;
                int cnt = dq.back().second;

                cost += 1LL * (nums[i] - value) * cnt;

                count += cnt;

                dq.pop_back();
            }

            // Insert the current group
            dq.push_back({nums[i], count});

            // Reduce window size if operations exceed k
            while (cost > k) {

                int value = dq.front().first;
                int cnt = dq.front().second;

                cost -= (value - nums[j]);

                j--;

                dq.pop_front();

                if (cnt > 1) {
                    dq.push_front({value, cnt - 1});
                }
            }

            // Count valid subarrays
            ans += (j - i + 1);
        }

        return ans;
    }
};
