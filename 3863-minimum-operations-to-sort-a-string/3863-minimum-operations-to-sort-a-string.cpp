class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        
        // Check if already sorted
        bool sorted = true;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] > s[i + 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) return 0;
        
        if (n == 2) return -1;
        
        char mn = s[0], mx = s[0];
        for (int i = 0; i < n; ++i) {
            if (s[i] < mn) mn = s[i];
            if (s[i] > mx) mx = s[i];
        }
        
        // Check if 1 operation is possible
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        // Check if 3 operations are needed
        bool onlyMaxAtStart = (s[0] == mx);
        for (int i = 1; i < n; ++i) {
            if (s[i] == mx) {
                onlyMaxAtStart = false;
                break;
            }
        }
        
        bool onlyMinAtEnd = (s[n - 1] == mn);
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == mn) {
                onlyMinAtEnd = false;
                break;
            }
        }
        
        if (onlyMaxAtStart && onlyMinAtEnd) {
            return 3;
        }
        
        return 2;
    }
};