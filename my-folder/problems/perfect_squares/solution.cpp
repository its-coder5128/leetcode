class Solution {
public:
    int solve(int n,int index,vector<vector<int>>& dp)
    {
        if(n == 0)
            return 0;
        if(n < 0 || index * index > n)
            return 1e9;
        if(dp[n][index] != -1)
            return dp[n][index];
        
        return dp[n][index] = min( 1 + solve(n-(index*index),index,dp) , solve(n,index+1,dp) );
    }
    int numSquares(int n) {
        vector<vector<int>> dp(n+1,vector<int>(sqrt(n)+2,1e9));
        for(int i = 0;i*i<=n;i++)
        {
            dp[0][i] = 0;
        }

        for(int i = 1;i <= n;i++)
        {
            for(int j = sqrt(i);j>=1;j--)
            {
                int x = 1 + dp[i-j*j][j];
                int y = dp[i][j+1];
                dp[i][j] = min( x , y );
            }
        }

        return dp[n][1];
    }
};