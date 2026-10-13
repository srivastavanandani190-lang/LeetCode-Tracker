class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];

        // 1. If source and target are the same square
        if (sr == tr && sc == tc) {
            return 0;
        }

        // 2. If they have different color parities, the bishop can never reach it
        if ((sr + sc) % 2 != (tr + tc) % 2) {
            return -1;
        }

        // 3. If they are already on the same diagonal, 1 move is enough
        if ((sr - sc == tr - tc) || (sr + sc == tr + tc)) {
            return 1;
        }

        // 4. Otherwise, it takes 2 moves
        return 2;
    }
};