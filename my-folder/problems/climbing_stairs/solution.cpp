class Solution {
public:
    int climbStairss(int n,vector<int> &dp)
    {
        if(n == 0)
            return 1;
        if(n == -1)
            return 0;
        if(dp[n] != -1)
            return dp[n];

        return dp[n] =climbStairss(n-1,dp) + climbStairss(n-2,dp);
    }
    
    int climbStairs(int n) {
        int p2 = 1;
        int p1 = 1;

        for(int i = 2;i<=n;i++)
        {
            int curr = p1 + p2;
            p2 = p1;
            p1 = curr;
        }

        return p1;
            
    }
};