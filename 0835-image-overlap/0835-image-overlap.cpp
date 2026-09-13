class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> v1, v2;
        
        // Collect coordinates of all 1s in both images
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) v1.push_back({i, j});
                if (img2[i][j] == 1) v2.push_back({i, j});
            }
        }
        
        int maxOverlap = 0;
        // n is up to 30, so coordinate differences range from -29 to +29.
        // We shift the index by 30 to store counts in a positive-indexed 2D array.
        int count[60][60] = {0}; 
        
        // Calculate translation vectors and count their frequencies
        for (auto& p1 : v1) {
            for (auto& p2 : v2) {
                int dx = p2.first - p1.first + 30;
                int dy = p2.second - p1.second + 30;
                
                count[dx][dy]++;
                maxOverlap = max(maxOverlap, count[dx][dy]);
            }
        }
        
        return maxOverlap;
    }
};