class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> res;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "C") {
                res.pop_back();
            }
            else if (operations[i] == "D") {
                res.push_back(2 * res.back());
            }
            else if (operations[i] == "+") {
                int n = res.size();
                res.push_back(res[n - 1] + res[n - 2]);
            }
            else {
                // convert string to integer
                res.push_back(stoi(operations[i]));
            }
        }

        // calculate total sum
        int sum = 0;
        for (int x : res) {
            sum += x;
        }

        return sum;
    }
};