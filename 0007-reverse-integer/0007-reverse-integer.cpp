class Solution {
public:
    int reverse(int x) {
       long int rem,original;
        long int  sum=0;
        while(x>0 || x<0){
            rem=x%10;
            x=x/10;
            sum=sum*10+rem;
        }
        if(original>=0) {
            return sum;
        }
        else{
            return sum*(-1);
        }
    }
};