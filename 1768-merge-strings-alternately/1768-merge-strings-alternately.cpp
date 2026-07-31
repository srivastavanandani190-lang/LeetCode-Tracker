class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n = word1.size();
        int m = word2.size();
        int i = 0;
        
        // Loop while there are still characters left in at least one string
        while (i < n || i < m) {
            // If characters are left in word1, append one
            if (i < n) {
                ans += word1[i];
            }
            // If characters are left in word2, append one
            if (i < m) {
                ans += word2[i];
            }
            i++;
        }
        
        return ans;
    }
};