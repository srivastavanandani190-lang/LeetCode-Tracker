#include <vector>
#include <algorithm>

using namespace std;

// Represents the best outcome from a given state
struct State {
    long long score;
    int len;
    int ids[4]; // Fixed size to prevent dynamic allocation overhead in DP loop

    State() {
        score = 0;
        len = 0;
        ids[0] = ids[1] = ids[2] = ids[3] = 0;
    }
};

// Returns true if state 'a' is strictly better than state 'b'
bool isBetter(const State& a, const State& b) {
    if (a.score != b.score) {
        return a.score > b.score; // Higher score is strictly better
    }
    // For equal scores, we want the lexicographically SMALLER set of IDs
    for (int i = 0; i < a.len && i < b.len; ++i) {
        if (a.ids[i] != b.ids[i]) {
            return a.ids[i] < b.ids[i];
        }
    }
    // If they match up to the length of the shorter one, the shorter one is smaller
    return a.len < b.len;
}

struct Interval {
    int l, r, w, id;
    bool operator<(const Interval& other) const {
        if (l != other.l) return l < other.l;
        if (r != other.r) return r < other.r;
        if (w != other.w) return w > other.w;
        return id < other.id;
    }
};

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& raw_intervals) {
        int n = raw_intervals.size();
        vector<Interval> intervals(n);
        
        for (int i = 0; i < n; ++i) {
            intervals[i] = {raw_intervals[i][0], raw_intervals[i][1], raw_intervals[i][2], i};
        }
        
        // Sort intervals strictly by the left boundary
        sort(intervals.begin(), intervals.end());

        // dp[i][k] keeps track of best choices choosing up to k intervals from suffix i...n-1
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = n - 1; i >= 0; --i) {
            // Binary search to find the first next non-overlapping interval
            int target = intervals[i].r;
            int low = i + 1, high = n;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (intervals[mid].l > target) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            int j = low; // 'j' will be 'n' if no valid next interval exists

            for (int k = 1; k <= 4; ++k) {
                State skip = dp[i + 1][k];
                
                State take;
                take.score = (long long)intervals[i].w + dp[j][k - 1].score;
                take.len = dp[j][k - 1].len + 1;

                // Build array of ids for 'take' and keep them sorted
                take.ids[0] = intervals[i].id;
                for (int x = 0; x < dp[j][k - 1].len; ++x) {
                    take.ids[x + 1] = dp[j][k - 1].ids[x];
                }
                std::sort(take.ids, take.ids + take.len);

                // Lock in optimal choice
                if (isBetter(take, skip)) {
                    dp[i][k] = take;
                } else {
                    dp[i][k] = skip;
                }
            }
        }

        // DP base cell carries the optimal configuration
        vector<int> result;
        for (int i = 0; i < dp[0][4].len; ++i) {
            result.push_back(dp[0][4].ids[i]);
        }
        return result;
    }
};