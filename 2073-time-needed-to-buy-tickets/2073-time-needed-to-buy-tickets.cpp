class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        
        int time=0;
        for(int i=0;i<k;i++){
            time+=min(tickets[k],tickets[i]);
        }
        time+=tickets[k];
        for(int j=k+1;j<n;j++){
            time+=min(tickets[k]-1,tickets[j]);
        }
        
        return time;
    }
};