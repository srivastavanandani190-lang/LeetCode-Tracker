class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        
        for (string email : emails) {
            string local = "";
            string domain = "";
            bool plusFound = false;
            int i = 0;
            
            // Process local name
            while (email[i] != '@') {
                if (email[i] == '+') {
                    plusFound = true;
                }
                else if (email[i] == '.') {
                    // skip dots
                }
                else if (!plusFound) {
                    local += email[i];
                }
                i++;
            }
            
            // Skip '@'
            i++;
            
            // Get domain name
            while (i < email.size()) {
                domain += email[i];
                i++;
            }
            
            // Combine normalized email
            uniqueEmails.insert(local + "@" + domain);
        }
        
        return uniqueEmails.size();
    }
};