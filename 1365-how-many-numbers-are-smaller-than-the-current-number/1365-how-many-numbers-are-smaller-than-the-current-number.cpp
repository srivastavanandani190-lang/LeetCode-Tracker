class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // vector<int> sorted = nums;
        // sort(sorted.begin(), sorted.end());

        // unordered_map<int, int> mp;

        // for (int i = 0; i < sorted.size(); i++) {
        //     if (mp.find(sorted[i]) == mp.end()) {
        //         mp[sorted[i]] = i;  // first occurrence
        //     }
        // }

        // vector<int> ans;
        // for (int num : nums) {
        //     ans.push_back(mp[num]);
        // }

     vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> ans;
        
        // Step 2: Use lower_bound to find the count of smaller numbers
        for(int i = 0; i < nums.size(); i++){
            // lower_bound returns an iterator. Subtracting the begin() iterator 
            // gives the integer index/count of smaller elements.
            int count = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) - sorted_nums.begin();
            ans.push_back(count);
        }
        
        return ans;
    }
};