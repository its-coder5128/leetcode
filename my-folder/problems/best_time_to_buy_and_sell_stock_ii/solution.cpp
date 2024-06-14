class Solution {
public:
    int solve(vector<int>& prices,int index,int buy,vector<vector<int>> &dp)
    {
        int n = prices.size();
        if(index == n)  
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        if(buy)
            return dp[index][buy] = max( - prices[index] + solve(prices,index+1,0,dp), solve(prices,index+1,1,dp));
        else
            return dp[index][buy] = max( prices[index] + solve(prices,index+1,1,dp), solve(prices,index+1,0,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> next(2,0);
        vector<int> curr(2,0);

        for(int i = n-1;i>=0;i--)
        {
            
                
                    curr[1] = max( - prices[i] + next[0], next[1]);
                
                    curr[0] = max( prices[i] + next[1], next[0]);
            
            next = curr;
        }
        return next[1];
    }
};