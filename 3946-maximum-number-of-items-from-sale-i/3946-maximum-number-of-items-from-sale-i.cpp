class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        vector<int> freeCount(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    ++freeCount[i];
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int bonus = freeCount[i];
            if (price > budget) continue;

            vector<int> nextDp = dp;
            for (int b = price; b <= budget; ++b) {
                nextDp[b] = max(nextDp[b], dp[b - price] + 1 + bonus);
                nextDp[b] = max(nextDp[b], nextDp[b - price] + 1);
            }
            dp.swap(nextDp);
        }

        return dp[budget];
    }
};