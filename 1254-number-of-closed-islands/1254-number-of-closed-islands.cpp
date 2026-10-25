class Solution {
private:
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // If out of bounds, it means the island touches the border (not closed)
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }
        
        // If it's water (1), it's bounded
        if (grid[r][c] == 1) {
            return true;
        }
        
        // Mark the current cell as visited by changing it to 1
        grid[r][c] = 1;
        
        // Explore all 4 directions
        bool up = dfs(r - 1, c, grid);
        bool down = dfs(r + 1, c, grid);
        bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        
        // An island is closed only if all its parts are enclosed
        return up && down && left && right;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Eliminate all land cells connected to the edges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && grid[i][j] == 0) {
                    dfs(i, j, grid);
                }
            }
        }
        
        // Step 2: Count remaining isolated closed islands
        int closedIslandsCount = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    // If we find a 0, it's a closed island
                    closedIslandsCount++;
                    dfs(i, j, grid); // Sink this entire island
                }
            }
        }
        
        return closedIslandsCount;
    }
};