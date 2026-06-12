class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j = 0;  // pointer for target

        for (int i = 1; i <= n && j < target.size(); i++) {
            ans.push_back("Push");

            if (i == target[j]) {
                j++;   // keep this element
            } else {
                ans.push_back("Pop"); // remove unnecessary element
            }
        }

        return ans;
    }
};