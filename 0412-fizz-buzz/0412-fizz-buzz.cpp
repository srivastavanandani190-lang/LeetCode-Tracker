class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);   // 🔹 resize first

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 != 0) {
                res[i - 1] = "Fizz";
            }
            else if (i % 3 != 0 && i % 5 == 0) {
                res[i - 1] = "Buzz";
            }
            else if (i % 3 == 0 && i % 5 == 0) {
                res[i - 1] = "FizzBuzz";
            }
            else {
                res[i - 1] = to_string(i);  // 🔹 int → string
            }
        }
        return res;
    }
};