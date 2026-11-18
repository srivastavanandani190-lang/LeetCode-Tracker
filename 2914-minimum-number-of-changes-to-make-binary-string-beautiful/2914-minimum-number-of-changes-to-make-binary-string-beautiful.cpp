class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        // Step through the string in increments of 2
        for (int i = 0; i < s.length(); i += 2) {
            // If adjacent characters don't match, we need 1 change
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }
        return changes;
    }
};