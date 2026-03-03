class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);

            // keep only k largest elements
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // top of minHeap is kth largest element
        return minHeap.top();
    }
};