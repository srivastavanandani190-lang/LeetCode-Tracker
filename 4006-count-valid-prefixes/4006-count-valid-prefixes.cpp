class Solution {
public:
    int countValidPrefixes(string s) {
        int count0 = 0, count1 = 0;
        int validPrefixCount = 0;

        for (char c : s) {
            if (c == '0') {
                count0++;
            } else {
                count1++;
            }

            if (abs(count0 - count1) <= 1) {
                validPrefixCount++;
            }
        }

        return validPrefixCount;
    }
};