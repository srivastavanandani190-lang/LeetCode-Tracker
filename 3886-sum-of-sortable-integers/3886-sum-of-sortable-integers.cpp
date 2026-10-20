
#include <vector>
#include <algorithm>

class Solution {
private:
    bool isRotation(const std::vector<int>& nums,
                    const std::vector<int>& sorted,
                    int start, int k) {
        std::vector<int> lps(k, 0);

        // Build KMP prefix table
        for (int i = 1, len = 0; i < k; ) {
            if (sorted[start + i] == sorted[start + len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search for the sorted block in the circular block
        for (int i = 0, j = 0; i < 2 * k - 1; ) {
            int value = nums[start + (i % k)];

            if (value == sorted[start + j]) {
                ++i;
                ++j;

                if (j == k)
                    return true;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }

        return false;
    }

public:
    long long sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();

        std::vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());

        long long ans = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0)
                continue;

            bool possible = true;

            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sorted, start, k)) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans += k;
        }

        return ans;
    }
};
