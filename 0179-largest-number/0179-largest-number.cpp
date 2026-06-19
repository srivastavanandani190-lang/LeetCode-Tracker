class Solution {
public:
    string largestNumber(vector<int>& nums) {
         vector<string> v;
        v.reserve(nums.size());

        for (int x : nums)
            v.push_back(to_string(x));

        sort(v.begin(), v.end(),
            [](const string& a, const string& b) {
                return a + b > b + a;
            });

        if (v[0] == "0")
            return "0";

        string ans;
        for (const string& s : v)
            ans += s;

        return ans;
    }
};