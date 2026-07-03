class MedianFinder {
public:
    priority_queue<int> left; // Max Heap
    priority_queue<int, vector<int>, greater<int>> right; // Min Heap

    MedianFinder() {
        
    }

    void addNum(int num) {

        if (left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);

        // Balance the heaps
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
        else if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
    }

    double findMedian() {

        if (left.size() > right.size())
            return left.top();

        return (left.top() + right.top()) / 2.0;
    }
};