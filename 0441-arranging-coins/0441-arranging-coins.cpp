class Solution {
public:
    int arrangeCoins(int n) {
        // Cast to double/long to prevent overflow when calculating 8 * n
        return (sqrt(8.0 * n + 1) - 1) / 2;
    }
};