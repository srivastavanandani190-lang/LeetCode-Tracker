class Solution {
    int memo[100][100][205];
    int m, n;
    
    bool dfs(int r, int c, int bal, const vector<vector<char>>& grid) {
        // Out of bounds
        if (r >= m || c >= n) return false;
        
        // Update balance
        bal += (grid[r][c] == '(' ? 1 : -1);
        
        // If balance drops below 0, it's an invalid string.
        // Balance can't exceed (m + n) / 2 because we wouldn't have enough remaining steps to close them.
        if (bal < 0 || bal > (m + n) / 2) return false; 
        
        // Reached bottom-right corner
        if (r == m - 1 && c == n - 1) return bal == 0;
        
        // Return pre-computed result if available
        if (memo[r][c][bal] != -1) return memo[r][c][bal];
        
        // Move down or right
        bool res = dfs(r + 1, c, bal, grid) || dfs(r, c + 1, bal, grid);
        
        return memo[r][c][bal] = res;
    }
    
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // Pruning: A valid parentheses string must have an even length.
        // The total path length is m + n - 1.
        if ((m + n - 1) % 2 != 0) return false;
        
        // Pruning: Path must start with '(' and end with ')'
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;
        
        memset(memo, -1, sizeof(memo));
        
        return dfs(0, 0, 0, grid);
    }
};