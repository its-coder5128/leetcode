class Solution {
public:
    int solve(vector<int> &prices,int buy,int index,vector<vector<int>> &dp)
    {
        if(index == prices.size())
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if(buy)
        {
            int take = -prices[index] + solve(prices,0,index+1,dp);
            int notTake = 0 + solve(prices,1,index+1,dp);
            profit = max(take,notTake);
        }
        if(!buy)
        {
            int take = prices[index] + solve(prices,1,index+1,dp);
            int notTake = 0 + solve(prices,0,index+1,dp);
            profit = max(take,notTake);
        }

        dp[index][buy] = profit;
        return profit;
    }
    int solveTab(vector<int>& prices)
    {
        int n = prices.size();

        //vector<vector<int>> dp(prices.size()+1,vector<int>(2,-0));
        vector<int> curr(2,0);
        vector<int> next(2,0);

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
                int profit = 0;
                if(buy)
                {
                    int take = -prices[index] + next[0];
                    int notTake = 0 + next[1];
                    profit = max(take,notTake);
                }
                if(!buy)
                {
                    int take = prices[index] + next[1];
                    int notTake = 0 + next[0];
                    profit = max(take,notTake);
                }

                curr[buy] = profit;
            }
            next = curr;
        }

        return curr[1];
    }
    int maxProfit(vector<int>& prices) {

        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));

        // return solve(prices,1,0,dp);
        return solveTab(prices);
        
    }
};