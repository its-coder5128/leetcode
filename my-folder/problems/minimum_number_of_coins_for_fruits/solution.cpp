class Solution {
public:
    int solve(vector<int> &prices,int index,int left,vector<unordered_map<int,int>> &dp)
    {
        if(index == prices.size())
            return 0;
        if(dp[index].find(left) != dp[index].end())
            return dp[index][left];
        
        int take = prices[index] + solve(prices,index+1,index+1,dp);
        
        int notTake = INT_MAX;
        if(left)
            notTake = 0 + solve(prices,index+1,left-1,dp);
        
        return dp[index][left] = min(take,notTake);
    }
    int minimumCoins(vector<int>& prices) {
        
        vector<unordered_map<int,int>> dp(prices.size());
        
        return prices[0] + solve(prices,1,1,dp);
        
    }
};