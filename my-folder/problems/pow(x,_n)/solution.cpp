class Solution {
public:
    double myPower(double x, int n) 
    {
        if(n == 0)
            return 1;
        
        if(n & 1)
            return x * myPower(x*x , n/2);
        else
            return myPower(x*x,n/2);
    }

    double myPow(double x, int n) {

        if(x == 1)
            return 1;

        double ans = myPower(x,abs(n));

        if(n < 0)
            ans = 1/ans;
        
        return ans;
        
    }
};