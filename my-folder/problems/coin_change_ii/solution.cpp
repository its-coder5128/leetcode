class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(2,vector<int>(amount+1,0));

        for(int i= 0;i<=amount;i++)
            if(i%coins[0] == 0) dp[0][i] = 1;

        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<=amount;j++)
            {
                int notTake = dp[0][j];
                int take = 0;
                if(j >= coins[i])
                    take = dp[1][j-coins[i]];
                
                dp[1][j] = take + notTake;
            }
            dp[0] = dp[1];
        }
        return  dp[0][amount];
    }
};