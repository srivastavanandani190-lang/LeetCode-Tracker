#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // 1. Find the position of 0
        int pos_0 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                pos_0 = i;
                break;
            }
        }

        // 2. Determine if the array is cyclically increasing or decreasing
        bool is_inc = true;
        for (int k = 0; k < n; ++k) {
            if (nums[(pos_0 + k) % n] != k) {
                is_inc = false;
                break;
            }
        }

        bool is_dec = true;
        for (int k = 0; k < n; ++k) {
            if (nums[(pos_0 - k + n) % n] != k) {
                is_dec = false;
                break;
            }
        }

        if (!is_inc && !is_dec) return -1;

        int start_dir = is_inc ? 0 : 1;

        // 3. BFS over the 2n state graph
        // State: (dir, pos_0), where dir in {0 (inc), 1 (dec)}
        std::vector<std::vector<int>> dist(2, std::vector<int>(n, -1));
        std::queue<std::pair<int, int>> q;

        q.push({start_dir, pos_0});
        dist[start_dir][pos_0] = 0;

        while (!q.empty()) {
            auto [dir, p] = q.front();
            q.pop();

            // Goal: cyclically increasing and 0 is at index 0
            if (dir == 0 && p == 0) {
                return dist[dir][p];
            }

            // Operation 1: Rotate Left
            int next_p_rot = (p - 1 + n) % n;
            if (dist[dir][next_p_rot] == -1) {
                dist[dir][next_p_rot] = dist[dir][p] + 1;
                q.push({dir, next_p_rot});
            }

            // Operation 2: Reverse
            int next_dir_rev = 1 - dir;
            int next_p_rev = n - 1 - p;
            if (dist[next_dir_rev][next_p_rev] == -1) {
                dist[next_dir_rev][next_p_rev] = dist[dir][p] + 1;
                q.push({next_dir_rev, next_p_rev});
            }
        }

        return -1;
    }
};