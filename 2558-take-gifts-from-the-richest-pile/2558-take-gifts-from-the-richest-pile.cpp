class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> p;

        for (int x : gifts)
            p.push(x);

        while (k--) {
            long long x = p.top();
            p.pop();
            p.push((long long)sqrt(x));
        }

        long long cost = 0;

        while (!p.empty()) {
            cost += p.top();
            p.pop();
        }

        return cost;
    }
};