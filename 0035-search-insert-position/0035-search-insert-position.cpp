class Solution {
public:
    int searchInsert(vector<int>& arr, int k) {
        // int low = 0, high = nums.size() - 1;

        // while (low <= high) {
        //     int mid = low + (high - low) / 2;

        //     if (nums[mid] == target) {
        //         return mid;
        //     } 
        //     else if (nums[mid] < target) {
        //         low = mid + 1;
        //     } 
        //     else {
        //         high = mid - 1;
        //     }
        // }
        // return low;  // insertion position
            int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==k){
                return i;
            }
            else if(arr[i]>k){
                return i;
                
            }
        }
        return n;
    }
};
