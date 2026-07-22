class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int count = 0, index = 0;

        while (index < s.size()) {
            if (s[index] == ' ') {
                int pos = temp.back() - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
            } else {
                temp += s[index];
            }
            index++;
        }

        int pos = temp.back() - '0';
        temp.pop_back();
        ans[pos] = temp;

        string res;

        for (int i = 1; i <= count + 1; i++) {
            res += ans[i];
            if (i != count + 1)
                res += " ";
        }

        return res;
    }
};