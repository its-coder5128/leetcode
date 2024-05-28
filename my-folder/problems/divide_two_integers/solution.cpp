class Solution {
public:
    int divide(int dividend, int divisor) {
        
        bool sign = true;

        if(dividend >=0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor > 0) sign = false;


        long long n = abs(dividend);
        long long d = abs(divisor);

        long long ans = 0;

        while( n >= d)
        {
            long cnt = 0;

            while((n - (d<<cnt)) >= 0)
            {
                cnt++;
            }
            cnt--;

            ans += 1ll*1<<cnt;
            
            // cout<<cnt<<endl;
            n -= d<<cnt;
        }

        if(ans >= INT_MAX && sign)   return INT_MAX;
        if(ans >= 1ll*INT_MAX+1 && !sign)   return INT_MIN;

        // cout<<ans<<" "<<sign;
        return sign ? ans : -ans;
    }
};