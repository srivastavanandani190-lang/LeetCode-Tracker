class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        int pro = 1;
        int zeroCount = 0;

        // Step 1: Calculate product of non-zero elements & count zeros
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zeroCount++;
            } else {
                pro *= nums[i];
            }
        }

        // Step 2: Build result based on zero count
        for(int i = 0; i < n; i++){
            if(zeroCount > 1){
                result.push_back(0);
            }
            else if(zeroCount == 1){
                if(nums[i] == 0){
                    result.push_back(pro); // only zero gets product
                } else {
                    result.push_back(0);
                }
            }
            else{
                result.push_back(pro / nums[i]);
            }
        }

        return result;
    }
};

