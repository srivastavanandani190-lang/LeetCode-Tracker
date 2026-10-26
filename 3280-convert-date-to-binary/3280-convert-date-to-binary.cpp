class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        auto toBinary = [](int n) {
            string s = "";
            while (n > 0) {
                s += (n % 2 == 0 ? '0' : '1');
                n /= 2;
            }
            reverse(s.begin(), s.end());
            return s;
        };
        
        return toBinary(year) + "-" + toBinary(month) + "-" + toBinary(day);
    }
};