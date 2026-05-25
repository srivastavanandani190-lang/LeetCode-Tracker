class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int left = j + 1;
                int right = n - 1;

                while(left < right) {

                    long long sum = (long long)nums[i] + nums[j] 
                                    + nums[left] + nums[right];

                    if(sum == target) {

                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left - 1])
                            left++;

                        while(left < right && nums[right] == nums[right + 1])
                            right--;
                    }

                    else if(sum < target)
                        left++;

                    else
                        right--;
                }

                while(j + 1 < n && nums[j] == nums[j + 1])
                    j++;
            }

            while(i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }

        return ans;
    }
};