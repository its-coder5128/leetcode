class Solution {
public:
    int solve(vector<int>& prices,int index,int buy, int fee,vector<vector<int>> &dp)
    {
        if(index == prices.size())
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        int profit = 0;

        if(buy)
        {
            int take = -prices[index] + solve(prices,index+1,0,fee,dp);
            int notTake = solve(prices,index+1,1,fee,dp);

            profit = max(take,notTake);
        }
        else{
            int take = prices[index] + solve(prices,index+1,1,fee,dp) - fee;
            int notTake = solve(prices,index+1,0,fee,dp);

            profit = max(take,notTake);

        }

        dp[index][buy] = profit;
        return profit;
    }
    int solveTab(vector<int>& prices, int fee)
    {
        //vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));

        vector<int> curr(2,0);
        vector<int> next(2,0);

        for(int index = prices.size() - 1;index>=0;index--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                int profit = 0;

                if(buy)
                {
                    int take = -prices[index] + next[0];
                    int notTake = next[1];

                    profit = max(take,notTake);
                }
                else{
                    int take = prices[index] + next[1] - fee;
                    int notTake = next[0];

                    profit = max(take,notTake);

                }

                curr[buy] = profit;
            }

            next = curr;
        }

        return next[1];


    }
    int maxProfit(vector<int>& prices, int fee) {

        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));

        // return solve(prices,0,1,fee,dp);

        return solveTab(prices,fee);
        
    }
};