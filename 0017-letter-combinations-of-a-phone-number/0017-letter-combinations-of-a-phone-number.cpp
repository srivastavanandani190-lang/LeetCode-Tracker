class Solution {
public:
    void solve(int index, string &digits, string &output,
               vector<string> &ans, vector<string> &mapping) {

        // Base case
        if (index >= digits.size()) {
            ans.push_back(output);
            return;
        }

        int num = digits[index] - '0';
        string letters = mapping[num];

        for (char ch : letters) {
            output.push_back(ch);
            solve(index + 1, digits, output, ans, mapping);
            output.pop_back(); // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty())
            return ans;

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string output = "";

        solve(0, digits, output, ans, mapping);

        return ans;
    }
};