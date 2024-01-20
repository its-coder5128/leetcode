class Solution {
public:
    int solve(vector<int>& nums,int index,int k,vector<vector<int>>& dp)
    {
        if(k == 0)
            return 0;
        if(index == nums.size())
            return 1e9;
        if(dp[index][k] != -1)
            return dp[index][k];
        
        int grp = solve(nums,index+1,k,dp);
        int notGrp = nums[index] + solve(nums,index+1,k-1,dp);
        
        return  dp[index][k]=min(grp,notGrp);
        
    }
    int minimumCost(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(3,-1));
        return nums[0] + solve(nums,1,2,dp);
    }
};