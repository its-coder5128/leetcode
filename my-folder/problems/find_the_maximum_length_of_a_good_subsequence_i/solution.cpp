class Solution {
public:
    int solve(int index,int prev,vector<int>& nums,int k,vector<vector<vector<int>>> &dp)
    {
        int n = nums.size();
        if(index == n)
            return 0;
        if(dp[index][k][prev+1] != -1)
        {
            return dp[index][k][prev+1];
        }
        
        int take = 0;
        int notTake = solve(index+1,prev,nums,k,dp);
        
        if(prev == -1)
            take = 1 + solve(index+1,index,nums,k,dp);
        else if(k - (nums[prev] != nums[index]) >= 0)
            take = 1 + solve(index+1,index,nums,k - (nums[prev] != nums[index]),dp);
        
        return dp[index][k][prev+1] = max(take,notTake);
            
    }
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(n+1,-1)));
        
        return solve(0,-1,nums,k,dp);
        
    }
};