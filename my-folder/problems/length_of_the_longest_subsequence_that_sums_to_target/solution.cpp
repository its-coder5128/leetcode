class Solution {
public:
    int solve(vector<int>& nums, int target,int index,vector<vector<int>> &dp)
    {
        if(target == 0)
            return 0;
        if(index>=nums.size() || target < 0)
            return INT_MIN;

        if(dp[index][target] != -1)
            return dp[index][target];
        
        int include = 1 + solve(nums,target - nums[index] , index+1,dp);
        int exclude = 0 + solve(nums,target,index+1,dp);
        
        return dp[index][target] = max(include,exclude);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));
        
        int ans = solve(nums,target,0,dp);
        
        if(ans>0)
            return ans;
        return -1;
        
    }
};