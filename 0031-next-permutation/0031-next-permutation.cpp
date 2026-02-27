class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    // 1. Find the pivot index
    int pivot = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }

    // 2. If pivot does not exist, reverse the whole array
    if (pivot == -1) {
        reverse(nums.begin(),nums.end());
        return;
    }

    // 3. Find the element from the right that is greater than pivot
    for (int i = n - 1; i > pivot; i--) {
        if (nums[i] > nums[pivot]) {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // 4. Reverse the elements from pivot + 1 to end
    int left = pivot + 1, right = n - 1;
    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }

    }
};