class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long islandSum = 0;
                    queue<pair<int, int>> q;
                    
                    q.push({i, j});
                    islandSum += grid[i][j];
                    grid[i][j] = 0; // Mark as visited
                    
                    int dr[] = {-1, 1, 0, 0};
                    int dc[] = {0, 0, -1, 1};
                    
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        
                        for (int d = 0; d < 4; ++d) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];
                            
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                islandSum += grid[nr][nc];
                                grid[nr][nc] = 0; // Mark as visited
                                q.push({nr, nc});
                            }
                        }
                    }
                    
                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};