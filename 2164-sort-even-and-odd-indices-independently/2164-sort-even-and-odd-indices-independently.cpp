class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> even(n, -1), odd(n, -1);

        // keep your idea: iterate with i += 2
        for (int i = 0; i < n; i += 2) {
            even[i] = nums[i];
        }

        for (int i = 1; i < n; i += 2) {
            odd[i] = nums[i];
        }

        // sort even indices (ascending)
        sort(even.begin(), even.end());

        // sort odd indices (descending)
        sort(odd.begin(), odd.end(), greater<int>());

        // merge back without changing index logic
        int e = 0, o = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                while (even[e] == -1) e++;
                nums[i] = even[e++];
            } else {
                while (odd[o] == -1) o++;
                nums[i] = odd[o++];
            }
        }

        return nums;
    }
};
