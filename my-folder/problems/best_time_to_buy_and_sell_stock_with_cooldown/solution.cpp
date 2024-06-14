class Solution {
public:
    int solve(vector<int>& prices,int index,int buy,vector<vector<int>>& dp)
    {
        if(index >= prices.size())
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        if(buy)
            return dp[index][buy] = max( - prices[index] + solve(prices,index+1,0,dp), solve(prices,index+1,1,dp));
        else
            return dp[index][buy] = max( prices[index] + solve(prices,index + 2, 1,dp), solve(prices,index+1,0,dp));
    }
    int maxProfit(vector<int>& prices) {

        vector<int> next2(2,0);
        vector<int> next1(2,0);
        vector<int> curr(2,0);

        for(int index = prices.size() - 1;index>=0;index--)
        {
          
            curr[1] = max( - prices[index] + next1[0], next1[1]);
                
            curr[0] = max( prices[index] + next2[1], next1[0]);
            
            next2 = next1;
            next1 = curr;
        }
        return next1[1];
    }
};