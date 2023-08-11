class Solution {
public:
    int solve(int amount, vector<int>& coins,int index,vector<vector<int>> &dp)
    {
        if(index == coins.size())
            return 0;
        if(amount == 0)
            return 1;
        if(amount < 0)
            return 0;
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        int include = solve(amount - coins[index],coins,index,dp);
        int exclude = solve(amount,coins,index+1,dp);

        return dp[index][amount] = include + exclude;
    }

    int solveTab(int tar, vector<int>& coins)
    {
        //vector<vector<int>> dp(coins.size()+1,vector<int>(tar+1,0));

        vector<int> curr(tar+1,0);
        vector<int> next(tar+1,0);

        // for(int i=0;i<=coins.size();i++)
        // {
        //     dp[i][0] = 1;
        // }
        curr[0]=1;
        next[0]=1;

        for(int index = coins.size()-1;index >= 0;index--)
        {
            for(int amount = 1;amount <=tar;amount++)
            {
                int include = 0;
                if(amount - coins[index]>=0)
                    include = curr[amount - coins[index]];
                int exclude = next[amount];

                curr[amount] = include + exclude;
            }

            next = curr;
        }

        return next[tar];
    }
    int change(int amount, vector<int>& coins) {

        // vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));

        // return solve(amount,coins,0,dp);

        return solveTab(amount,coins);
        
    }
};