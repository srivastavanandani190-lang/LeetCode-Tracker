class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto dateToDayOfYear = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };
        
        int aliceArrival = dateToDayOfYear(arriveAlice);
        int aliceLeave = dateToDayOfYear(leaveAlice);
        int bobArrival = dateToDayOfYear(arriveBob);
        int bobLeave = dateToDayOfYear(leaveBob);
        
        int startOverlap = max(aliceArrival, bobArrival);
        int endOverlap = min(aliceLeave, bobLeave);
        
        return max(0, endOverlap - startOverlap + 1);
    }
};