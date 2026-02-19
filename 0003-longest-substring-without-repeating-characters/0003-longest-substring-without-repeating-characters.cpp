class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> res(256, 0);
        int left = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            res[s[i]]++;

            while (res[s[i]] > 1) {
                res[s[left]]--;
                left++;
            }

            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};
