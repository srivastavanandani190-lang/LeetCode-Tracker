#include <vector>
#include <unordered_map>
#include <cstdint>

using namespace std;

class Solution {
    static constexpr uint64_t MOD1 = 1000000007ULL;
    static constexpr uint64_t MOD2 = 1000000009ULL;
    static constexpr uint64_t BASE1 = 100003ULL;
    static constexpr uint64_t BASE2 = 100019ULL;

    vector<uint64_t> p1, p2, h1, h2;

    uint64_t getHash(int l, int r) const {
        int len = r - l + 1;
        uint64_t x1 = (h1[r + 1] + MOD1 - (h1[l] * p1[len]) % MOD1) % MOD1;
        uint64_t x2 = (h2[r + 1] + MOD2 - (h2[l] * p2[len]) % MOD2) % MOD2;
        return (x1 << 32) | x2;
    }

    bool hasUniqueOfLen(int len, int n) const {
        unordered_map<uint64_t, int> freq;
        freq.reserve(static_cast<size_t>(n - len + 1) * 2);
        for (int i = 0; i + len - 1 < n; ++i) {
            uint64_t key = getHash(i, i + len - 1);
            ++freq[key];
        }
        for (const auto& kv : freq) {
            if (kv.second == 1) return true;
        }
        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            uint64_t val = static_cast<uint64_t>(nums[i]);
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
            h1[i + 1] = (h1[i] * BASE1 + val) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + val) % MOD2;
        }

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUniqueOfLen(mid, n)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};