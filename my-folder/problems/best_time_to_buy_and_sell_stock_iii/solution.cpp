class Solution {
public:
    int solve(vector<int> &prices,int index,int buy,int x,vector<vector<vector<int>>> &dp)
    {
        if(index == prices.size() || x == 0)
        {
            return 0;
        } 
        if(dp[index][buy][x] != -1)
            return dp[index][buy][x];

        int profit = 0;

        if(buy)
        {
            int take = -prices[index] + solve(prices,index+1,0,x,dp);
            int notTake = 0 + solve(prices,index+1,1,x,dp);

            profit = max(take,notTake);
        }
        if(!buy)
        {
            int take = prices[index] + solve(prices,index+1,1,x-1,dp);
            int notTake = 0 + solve(prices,index+1,0,x,dp);

            profit = max(take,notTake);

        }

        dp[index][buy][x]=profit;

        return profit;
    }
    int solveTab(vector<int>& prices)
    {
        //vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));

        for(int index = prices.size()-1;index>=0;index--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                for(int x=2;x>=1;x--)
                {
                    int profit = 0;

                    if(buy)
                    {
                        int take = -prices[index] + next[0][x];
                        int notTake = 0 + next[1][x];

                        profit = max(take,notTake);
                    }
                    if(!buy)
                    {
                        int take = prices[index] + next[1][x-1];
                        int notTake = 0 + next[0][x];

                        profit = max(take,notTake);

                    }

                    curr[buy][x]=profit;
                }

            }
                next = curr;
        }

        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {

        // vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        
        // return solve(prices,0,1,2,dp);
        return solveTab(prices);
        
    }
};