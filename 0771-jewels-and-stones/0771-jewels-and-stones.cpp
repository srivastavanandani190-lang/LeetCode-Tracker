class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;

        for(int i = 0; i < stones.size(); i++) {
            int j = 0;

            while(j < jewels.size()) {
                if(jewels[j] == stones[i]) {
                    count++;
                    break;
                }
                j++;
            }
        }

        return count;
    }
};