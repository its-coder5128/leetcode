class Solution {
public:
    int solve(int s,int e,vector<vector<int>> &dp)
    {
        if(s>=e)
            return 0;

        if(dp[s][e] != -1)
            return dp[s][e];

        int ans = 0;
        int mini =  INT_MAX;
        for(int i=s;i<=e;i++)
        {
            ans = i + max(solve(s,i-1,dp),solve(i+1,e,dp));
    
            mini = min(ans,mini);
        }

        dp[s][e] = mini;
        return mini;
    }
    int solveTab(int n)
    {
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int s = n;s>=1;s--)
        {
            for(int e=s+1;e<=n;e++)
            {
                int ans = 0;
                int mini =  INT_MAX;
                for(int i=s;i<=e;i++)
                {
                    ans = i + max(dp[s][i-1],dp[i+1][e]);
            
                    mini = min(ans,mini);
                }

                dp[s][e] = mini;
            }
        }

        return dp[1][n];

    }
    int getMoneyAmount(int n) {

        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solve(1,n,dp);
        
        return solveTab(n);
    }
};