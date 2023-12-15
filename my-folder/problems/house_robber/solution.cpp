class Solution {
public:
    int solve(vector<int>& nums,int index,int prev,vector<vector<int>>& dp)
    {
        if(index == nums.size())
            return 0;
        if(dp[index][prev] != -1)
            return dp[index][prev];
        
        int notTake = 0 + solve(nums,index+1,false,dp);
        int take = 0;
        if(prev == false)
            take = nums[index] + solve(nums,index+1,true,dp);
        
        return dp[index][prev] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return solve(nums,0,false,dp);
        
    }
};