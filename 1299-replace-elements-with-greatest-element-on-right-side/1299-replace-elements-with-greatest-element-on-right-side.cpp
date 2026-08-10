class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        int max_val = arr[n - 1];
        ans.push_back(-1); // The last element should always be replaced by -1
        
        for (int i = n - 2; i >= 0; i--) {
            ans.push_back(max_val); // Push the current maximum found on the right
            if (arr[i] > max_val) {
                max_val = arr[i]; // Update max_val if a larger element is found
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};