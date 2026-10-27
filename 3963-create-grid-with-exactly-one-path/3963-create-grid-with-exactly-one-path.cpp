class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '.'));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j < n - 1) {
                    grid[i][j] = '.';
                } else if (j == n - 1 && i < m) {
                    grid[i][j] = '.';
                } else {
                    grid[i][j] = '#';
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                grid[i][j] = '#';
            }
        }
        // Let's create a simple path: go all the way right on row 0, then all the way down on column n-1.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == n - 1) {
                    grid[i][j] = '.';
                } else {
                    grid[i][j] = '#';
                }
            }
        }
        return grid;
    }
};