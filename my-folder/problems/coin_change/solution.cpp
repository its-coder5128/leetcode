class Solution {
public:
    int solve(int n,int k,vector<int>& coins,vector<vector<int>>& dp)
    {
        if( n == 0 )
        {
            if(k%coins[0] == 0) return k/coins[0];
            else return 1e9;
        }
        if(dp[n][k] != -1)
            return dp[n][k];

        int notTake = solve(n-1,k,coins,dp);
        int take = 1e9;
        if(coins[n] <= k)
            take = 1 + solve(n,k - coins[n],coins,dp);
        
        return dp[n][k] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(2,vector<int>(amount+1,1e9));

        for(int i = 0;i<=amount;i++)    
            if(i%coins[0] == 0) dp[0][i] = i/coins[0];
        
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<=amount;j++)
            {
                int notTake = dp[0][j];
                int take = 1e9;
                if(coins[i] <= j)
                    take = 1 + dp[1][j-coins[i]];
                
                dp[1][j] = min(take,notTake);
            }
            dp[0] = dp[1];
        }

        int ans = dp[0][amount];
        return ans >= 1e9 ? -1 : ans;
    }
};