#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> sq(n);
        
        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            sq[i] = (long long)nums[i] * nums[i];
            total_sum += sq[i];
        }
        
        // Sort the squares in ascending order
        std::sort(sq.begin(), sq.end());
        
        // Subtract 2 * (sum of the smallest n / 2 elements)
        long long smallest_half_sum = 0;
        int k = n / 2;
        for (int i = 0; i < k; ++i) {
            smallest_half_sum += sq[i];
        }
        
        return total_sum - 2 * smallest_half_sum;
    }
};