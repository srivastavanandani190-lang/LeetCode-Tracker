class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        // go[i][j][0] stores the landing (r, c) when entering (i, j) from the left (moving right)
        // go[i][j][1] stores the landing (r, c) when entering (i, j) from above (moving down)
        vector<vector<array<pair<int, int>, 2>>> go(m, vector<array<pair<int, int>, 2>>(n));

        // Helper function to simulate reflections recursively or iteratively for a given entry move
        auto get_landing = [&](int r, int c, int dir, auto& self) -> pair<int, int> {
            // dir: 0 means entering while moving right (so we try to enter (r, c)), 
            // but if (r, c) is a mirror, we turn down to (r + 1, c).
            // dir: 1 means entering while moving down (so we try to enter (r, c)),
            // but if (r, c) is a mirror, we turn right to (r, c + 1).
            int cur_r = r, cur_c = c;
            int cur_dir = dir;

            while (true) {
                // Check bounds
                if (cur_r < 0 || cur_r >= m || cur_c < 0 || cur_c >= n) {
                    return {-1, -1}; // Out of bounds
                }
                if (grid[cur_r][cur_c] == 0) {
                    return {cur_r, cur_c}; // Reached an empty cell
                }
                // If it's a mirror (grid[cur_r][cur_c] == 1), reflect based on entry direction
                if (cur_dir == 0) {
                    // Entered moving right -> turns down
                    cur_r += 1;
                    cur_dir = 1;
                } else {
                    // Entered moving down -> turns right
                    cur_c += 1;
                    cur_dir = 0;
                }
            }
        };

        // Precompute jump targets for all cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we try to move right into (i, j): target cell is (i, j) if empty, else reflected
                if (j < n) {
                    // Entering cell (i, j) from left (moving right)
                    int r = i, c = j, dir = 0;
                    if (grid[r][c] == 1) { r += 1; dir = 1; }
                    go[i][j][0] = get_landing(r, c, dir, get_landing);
                }
                // If we try to move down into (i, j)
                if (i < m) {
                    // Entering cell (i, j) from top (moving down)
                    int r = i, c = j, dir = 1;
                    if (grid[r][c] == 1) { c += 1; dir = 0; }
                    go[i][j][1] = get_landing(r, c, dir, get_landing);
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                // Option 1: Try moving right (which targets cell to the right: (i, j + 1))
                if (j + 1 < n) {
                    auto [next_r, next_c] = go[i][j + 1][0];
                    if (next_r != -1) {
                        dp[next_r][next_c] = (dp[next_r][next_c] + dp[i][j]) % MOD;
                    }
                }

                // Option 2: Try moving down (which targets cell below: (i + 1, j))
                if (i + 1 < m) {
                    auto [next_r, next_c] = go[i + 1][j][1];
                    if (next_r != -1) {
                        dp[next_r][next_c] = (dp[next_r][next_c] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};