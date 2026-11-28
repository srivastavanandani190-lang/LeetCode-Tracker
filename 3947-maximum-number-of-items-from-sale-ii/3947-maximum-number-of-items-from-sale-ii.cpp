
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        long long min_price = LLONG_MAX;

        // Count frequency of each factor
        for (const auto& it : items) {
            freq[it[0]]++;
            min_price = min(min_price, (long long)it[1]);
        }

        // Count items having factors that are multiples
        vector<int> mult_count(n + 1, 0);

        for (int d = 1; d <= n; d++) {
            if (freq[d] == 0) continue;

            for (int m = 2 * d; m <= n; m += d) {
                mult_count[d] += freq[m];
            }
        }

        // Store price and number of possible free items
        vector<pair<long long, long long>> pairs;

        for (const auto& it : items) {
            int f = it[0];
            long long p = it[1];

            long long gain = freq[f] - 1 + mult_count[f];

            if (gain > 0) {
                pairs.emplace_back(p, gain);
            }
        }

        // Sort by increasing price
        sort(pairs.begin(), pairs.end());

        long long rem = budget;
        long long ans = 0;

        for (const auto& [p, gain] : pairs) {

            // Buying two copies separately is better or equal
            if (p >= 2 * min_price) break;

            // Cannot afford this item or any subsequent item
            if (rem < p) break;

            // Buy as many beneficial copies as possible
            long long take = min(gain, rem / p);

            ans += 2 * take;
            rem -= take * p;
        }

        // Spend remaining budget on the cheapest item
        ans += rem / min_price;

        return (int)ans;
    }
};
