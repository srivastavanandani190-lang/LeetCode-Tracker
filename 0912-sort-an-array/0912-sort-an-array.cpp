class Solution {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void BuildMaxHeap(vector<int>& arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    void sortarray(vector<int>& arr, int n) {
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

     vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        BuildMaxHeap(nums, n);
        sortarray(nums, n);
        return nums;
    }
};