class Solution {
public:
    int solve(vector<int>& prices,int index,int buy,int tot,vector<vector<vector<int>>> &dp)
    {
        int n = prices.size();
        if(index == n || tot == 0)  
            return 0;
        if(dp[index][buy][tot] != -1)
            return dp[index][buy][tot];
        
        if(buy)
            return dp[index][buy][tot] = max( - prices[index] + solve(prices,index+1,0,tot,dp), solve(prices,index+1,1,tot,dp));
        else
            return dp[index][buy][tot] = max( prices[index] + solve(prices,index+1,1,tot-1,dp), solve(prices,index+1,0,tot,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> next(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));

        for(int i = n-1;i>=0;i--)
        {
                for(int k = 1;k<3;k++)
                {
                    
                        curr[1][k] = max( - prices[i] + next[0][k], next[1][k]);

                        curr[0][k] = max( prices[i] + next[1][k-1], next[0][k]);
                }
            next = curr;
        }

        return next[1][2];
        
    }
};