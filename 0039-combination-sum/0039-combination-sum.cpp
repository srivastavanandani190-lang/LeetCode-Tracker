class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& ans) {
        
        // Base case
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Traverse candidates
        for (int i = idx; i < candidates.size(); i++) {

            // Skip if element is greater than target
            if (candidates[i] > target) continue;

            // Pick element
            temp.push_back(candidates[i]);

            // Recur (same index because elements can repeat)
            solve(i, candidates, target - candidates[i], temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, temp, ans);

        return ans;
    }
};