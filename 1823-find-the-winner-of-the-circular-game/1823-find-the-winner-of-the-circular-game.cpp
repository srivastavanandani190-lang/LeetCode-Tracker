class Solution {
public:
    int winner(vector<bool>& person, int n, int index, int person_left, int k) {

        // Only one person is left
        if (person_left == 1) {
            for (int i = 0; i < n; i++) {
                if (person[i] == 0) {
                    return i;
                }
            }
        }

        // Find the person who has to be eliminated
        int kill = (k - 1) % person_left;

        while (kill > 0) {
            index = (index + 1) % n;

            // Skip eliminated persons
            while (person[index] == 1) {
                index = (index + 1) % n;
            }

            kill--;
        }

        // Eliminate current person
        person[index] = 1;

        // Find the next alive person
        // do {
        //     index = (index + 1) % n;
        // } while (person[index] == 1);
         while (person[index] == 1) {
                index = (index + 1) % n;
            }

        return winner(person, n, index, person_left - 1, k);
    }

    int findTheWinner(int n, int k) {
        vector<bool> person(n, false);

        return winner(person, n, 0, n, k) + 1;
    }
};