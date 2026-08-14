class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();   
        
        // Notice there is no i++ here in the loop definition
        for(int i = 0; i < n; ){ 
            if(nums[i] == 0){
                nums.push_back(0);
                nums.erase(nums.begin() + i);
                
                // Shrink the boundary so we don't process the zeroes we just added to the back
                n--; 
            } else {
                // Only move to the next index if we DID NOT erase an element
                i++; 
            }
        }
    }
};