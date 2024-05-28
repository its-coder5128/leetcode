class Solution {
public:
    double solve(double x, long n)
    {
        double ans = 1;
        while( n > 0)
        {
            if(n%2 == 0)
            {
                x = x*x;
                n = n/2;
            }else{
                ans *= x;
                x = x*x;
                n = n/2;
            }
            cout<<ans<<endl;
        }
        return ans;
    }
    double myPow(double x, int n) {
        
        double ans = solve(x,abs(n));

        if(n < 0)
            return 1/ans;

        return ans; 
    }
};