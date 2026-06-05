class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> b(n);
        string s = b.to_string();
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                count++;
            }
        }
        return count;
    }
};