class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0;
        long long count = 0;

        for (int num : nums) {
            if (num == 0) {
                count++;
                total += count;
            } else {
                count = 0;
            }
        }

        return total;
    }
};