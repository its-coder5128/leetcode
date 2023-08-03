class Solution {
public:
    int solve(vector<int>& prices,int index,int buy,int k,vector<vector<vector<int> > > &dp)
    {
        if(index == prices.size() || k == 0)
        {
            return 0;
        }
        if(dp[index][buy][k] != -1)
            return dp[index][buy][k];
        
        int profit = 0;

        if(buy)
        {
            int take = -prices[index] + solve(prices,index + 1,0,k,dp);
            int notTake = solve(prices,index + 1,1,k,dp);

            profit = max(take,notTake);
        }
        else{
            int take = prices[index] + solve(prices,index + 1,1,k-1,dp);
            int notTake = solve(prices,index + 1,0,k,dp);

            profit = max(take,notTake);

        }

        dp[index][buy][k] = profit;
        return profit;
    }
    int solveTab(int limit, vector<int>& prices)
    {
        //vector<vector<vector<int> > > dp(prices.size() + 1,vector<vector<int>>(2,vector<int>(limit+1,0)));

        vector<vector<int>> curr(2,vector<int>(limit+1,0));
        vector<vector<int>> next(2,vector<int>(limit+1,0));

        for(int index = prices.size()-1;index>=0;index--)
        {
            for(int buy = 1;buy>=0;buy--)
            {
                for(int k=1;k<=limit;k++)
                {
                    int profit = 0;

                    if(buy)
                    {
                        int take = -prices[index] + next[0][k];
                        int notTake = next[1][k];

                        profit = max(take,notTake);
                    }
                    else{
                        int take = prices[index] + next[1][k-1];
                        int notTake = next[0][k];

                        profit = max(take,notTake);

                    }

                    curr[buy][k] = profit;
                }
            }

            next=curr;
        }
        return next[1][limit];
    }
    int maxProfit(int k, vector<int>& prices) {
        
        // vector<vector<vector<int> > > dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solve(prices,0,1,k,dp);

        return solveTab(k,prices);
    }
};