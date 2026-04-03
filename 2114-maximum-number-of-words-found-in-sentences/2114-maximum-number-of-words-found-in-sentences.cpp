class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;

        for(int i = 0; i < sentences.size(); i++) {
            int count = 1; // at least 1 word

            for(int j = 0; j < sentences[i].length(); j++) {
                if(sentences[i][j] == ' ') {
                    count++;
                }
            }

            maxWords = max(maxWords, count);
        }

        return maxWords;
    }
};