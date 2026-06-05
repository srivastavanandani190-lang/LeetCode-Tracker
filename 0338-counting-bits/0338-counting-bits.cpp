class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);

        for (int i = 0; i <= n; i++) {
            int count = 0;
            bitset<32> b(i);
            string s = b.to_string();

            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '1') {
                    count++;
                }
            }

            ans[i] = count;
        }

        return ans;
    }
};