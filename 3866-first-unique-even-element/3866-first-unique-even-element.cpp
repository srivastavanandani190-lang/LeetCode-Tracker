class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
           unordered_map<int, int> res;

        // Count frequencies of all numbers
        for(int i = 0; i < nums.size(); i++) {
           if(nums[i] % 2 == 0){
            res[nums[i]]++;
        }
        }

        int ans=-1;
 
       // Iterate through the original array to preserve index order
        for(int i = 0; i < nums.size(); i++) {
            if(  res[nums[i]] == 1){
                return nums[i];
            }
        }

        return ans;
    }
};