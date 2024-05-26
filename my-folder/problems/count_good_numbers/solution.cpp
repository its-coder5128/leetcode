class Solution {
    long long MOD = 1e9 + 7;
public:
    long long mypow(long long x,long long n)
    {
        if(n == 0)
            return 1*1ll;
        
        if(n&1)
            return (x%MOD * mypow((x*x)%MOD,n/2)%MOD)%MOD;
        else
            return (mypow((x*x)%MOD,n/2))%MOD;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n - odd;

        long long oddVal = mypow(4,odd)%MOD;
        long long evenVal = mypow(5,even)%MOD;

        return (oddVal * evenVal) % MOD;
    }
};