class Solution {
public:
    int getSum(const vector<int>& arr, int value) {
        int sum = 0;
        for (int x : arr) {
            sum += min(x, value);
        }
        return sum;
    }

    int findBestValue(vector<int>& arr, int target) {
        int left = 0;
        int right = 0;
        
        // The maximum possible optimal value won't exceed the max element in the array
        for (int x : arr) {
            right = max(right, x);
        }

        // Binary search to find the largest value that results in a sum <= target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (getSum(arr, mid) <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Compare the two closest values: `right` (sum <= target) and `left` (sum > target)
        int sum1 = getSum(arr, right);
        int sum2 = getSum(arr, left);

        // In case of a tie in absolute difference, the smaller value (right) is preferred
        if (abs(sum1 - target) <= abs(sum2 - target)) {
            return right;
        }
        
        return left;
    }
};