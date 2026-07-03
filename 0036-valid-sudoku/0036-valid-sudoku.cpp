class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') continue;

                string row = "r" + to_string(i) + board[i][j];
                string col = "c" + to_string(j) + board[i][j];
                string box = "b" + to_string(i/3) + to_string(j/3) + board[i][j];

                if (s.count(row) || s.count(col) || s.count(box))
                    return false;

                s.insert(row);
                s.insert(col);
                s.insert(box);
            }
        }

        return true;
    }
};