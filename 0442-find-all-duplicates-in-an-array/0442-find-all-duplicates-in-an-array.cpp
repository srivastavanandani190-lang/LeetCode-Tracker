class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
    
        vector<int> freq(arr.size() + 1, 0); 
        vector<int> ans;
        
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;         
            if (freq[arr[i]] > 1) { 
                ans.push_back(arr[i]);
            }
        }
        
        return ans;
    }
};