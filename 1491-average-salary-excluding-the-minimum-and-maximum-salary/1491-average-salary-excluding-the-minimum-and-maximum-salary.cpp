class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();
        int max=*max_element(salary.begin(),salary.end());
        int min=*min_element(salary.begin(),salary.end());
        double sum=0;
        for(int i=0;i<n;i++){
            sum=sum+salary[i];
        }
        double aveg=((sum-(max+min))/(n-2));
        return aveg;
    }
};