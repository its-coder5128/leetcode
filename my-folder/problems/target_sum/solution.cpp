class Solution {
public:
    int solve(vector<int>& nums, int target,int n,int prev,unordered_map<int,int> dp[])
    {
        if(n == 0)
        {
            if(prev == target && nums[0] == 0)
                return 2;
            if(nums[0] + prev == target )   
                return 1;
            if(-nums[0] + prev == target )   
                return 1;
            return 0;
        }
        if(dp[n].find(prev) != dp[n].end())
            return dp[n][prev];
        
        int add = solve(nums,target,n-1,nums[n] + prev,dp);
        int sub = solve(nums,target,n-1,-nums[n] + prev,dp);
        
        return dp[n][prev] = sub + add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // int sum = accumulate(nums.begin(),nums.end(),0);

        unordered_map<int,int> dp[n];

        return solve(nums,target,n-1,0,dp);
    }
};