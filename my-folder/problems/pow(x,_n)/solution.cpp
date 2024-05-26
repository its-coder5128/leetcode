class Solution {
public:
    double solve(double x, int n)
    {
        if(n == 0)
            return 1;
        
        if(n % 2 != 0)
            return x*solve(x*x,n/2);
        else
            return solve(x*x,n/2);
    }
    double myPow(double x, int n) {
        
        double ans = solve(x,abs(n));

        if(n < 0)
            return 1/ans;

        return ans; 
    }
};