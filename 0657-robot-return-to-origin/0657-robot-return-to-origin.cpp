class Solution {
public:
    bool judgeCircle(string moves) {
        int U = 0, D = 0, L = 0, R = 0;

        for (char move : moves) {
            if (move == 'U') U++;
            else if (move == 'D') D++;
            else if (move == 'L') L++;
            else if (move == 'R') R++;
        }

        return (U == D && L == R);
    }
};