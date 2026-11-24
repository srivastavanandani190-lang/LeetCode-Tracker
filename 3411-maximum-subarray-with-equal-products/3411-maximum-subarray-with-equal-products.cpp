#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long val = nums[j];
                if (prod > 1000000000000LL / val) {
                    break;
                }
                prod *= val;
                g = std::gcd(g, val);
                l = std::lcm(l, val);

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};