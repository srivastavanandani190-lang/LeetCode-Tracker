// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         return haystack.find(needle);
//     }
// };
class Solution {
public:
 void findLPS(vector<int>& lps, string& pattern) {
        int pre = 0;
        int suf = 1;

        while (suf < pattern.size()) {
            if (pattern[pre] == pattern[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        // int n = haystack.length();
        // int m = needle.length();
 
        // if (m == 0) return 0;
        // if (m > n) return -1;

     
        // for (int i = 0; i <= n - m; i++) {
        //     int j;
        //     for (j = 0; j < m; j++) {
        //         if (haystack[i + j] != needle[j]) {
        //             break;
        //         }
        //     }
 
        //     if (j == m) {
        //         return i;
        //     }
        // }

        // return -1;
        if (needle.empty())
            return 0;

        vector<int> lps(needle.size(), 0);
        findLPS(lps, needle);

        int first = 0, second = 0;

        while (first < haystack.size() && second < needle.size()) {
            if (haystack[first] == needle[second]) {
                first++;
                second++;
            } else {
                if (second == 0) {
                    first++;
                } else {
                    second = lps[second - 1];
                }
            }
        }

        if (second == needle.size())
            return first - second;

        return -1;
    }
};
