class Solution {
public:
    int maximum69Number (int num) {
        vector<int> res;

        // Step 1: extract digits
        while (num != 0) {
            res.push_back(num % 10);
            num /= 10;
        }

        // Step 2: reverse to get correct order
        reverse(res.begin(), res.end());

        // Step 3: change first 6 → 9
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == 6) {
                res[i] = 9;
                break;
            }
        }

        // Step 4: rebuild number
        int dig = 0;
        for (int i = 0; i < res.size(); i++) {
            dig = dig * 10 + res[i];
        }

        return dig;
    }
};