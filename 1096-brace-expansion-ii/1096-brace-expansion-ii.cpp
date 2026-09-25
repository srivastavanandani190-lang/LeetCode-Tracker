#include <vector>
#include <string>
#include <set>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        queue<string> q;
        set<string> res; // Uses a set to automatically handle sorting and deduplication
        
        q.push(expression);
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            // Find the first closing brace '}'
            size_t right = curr.find('}');
            
            if (right == string::npos) {
                // If there are no braces left, the string is fully expanded
                res.insert(curr);
                continue;
            }
            
            // Find the corresponding opening brace '{' for the innermost expression
            size_t left = curr.rfind('{', right);
            
            // Extract the surrounding text and the text to be expanded
            string before = curr.substr(0, left);
            string after = curr.substr(right + 1);
            string inside = curr.substr(left + 1, right - left - 1);
            
            // Split the inside content by commas and create new branches
            stringstream ss(inside);
            string part;
            while (getline(ss, part, ',')) {
                // Push the newly formed string back into the queue for further expansion
                q.push(before + part + after);
            }
        }
        
        // Convert the ordered set directly to the required vector format
        return vector<string>(res.begin(), res.end());
    }
};