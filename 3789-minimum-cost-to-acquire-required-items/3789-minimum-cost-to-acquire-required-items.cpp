class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cBoth = costBoth;
        long long n1 = need1;
        long long n2 = need2;

        long long common = min(n1, n2);
        long long rem1 = n1 - common;
        long long rem2 = n2 - common;

        long long totalCost = common * min(cBoth, c1 + c2);
        totalCost += rem1 * min(cBoth, c1);
        totalCost += rem2 * min(cBoth, c2);

        return totalCost;
    }
};