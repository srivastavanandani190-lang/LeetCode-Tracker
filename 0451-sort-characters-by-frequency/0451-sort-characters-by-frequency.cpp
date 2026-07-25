class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Step 2: Push into max-heap sorted by frequency
        priority_queue<pair<int, char>> maxHeap;
        for (auto& [ch, count] : freq) {
            maxHeap.push({count, ch});
        }
        
        // Step 3: Build the result string
        string result = "";
        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            result.append(count, ch);
        }
        
        return result;
    }
};