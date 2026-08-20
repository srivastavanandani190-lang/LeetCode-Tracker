class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        vector<int> freq(26, 0);

        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        int n = s.size();

        // Check possible substring lengths
        for(int len = 1; len <= n / 2; len++) {

            if(n % len != 0)
                continue;

            bool flag = true;

            for(int i = len; i < n; i++) {
                if(s[i] != s[i % len]) {
                    flag = false;
                    break;
                }
            }

            if(flag)
                return true;
        }

        return false;
    }
};