class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        if (n == 0) return false;
        int m = mat[0].size();
        
        // Start from the top-right corner
        int i = 0;
        int j = m - 1;
        
        while (i < n && j >= 0) {
            if (mat[i][j] == x) {
                return true; 
            } else if (mat[i][j] > x) {
                j--; // Move left
            } else {
                i++; // Move down
            }
        }
        
        return false;
    }
};