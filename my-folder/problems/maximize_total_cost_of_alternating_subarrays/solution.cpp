class Solution {
public:
    long long solve(vector<int>& nums,int index,int coeff,vector<vector<long long>>& dp)
    {
        if(index == nums.size())
        {
            return 0;
        }
        if(dp[index][coeff] != -1)
            return dp[index][coeff];
        long long x = nums[index];
        if(coeff == 0)
            x = -x;
        long long subArr = x + solve(nums,index+1,!coeff,dp);
        long long startSub = nums[index] + solve(nums,index+1,0,dp);

        return dp[index][coeff] = max(subArr,startSub);
    }
    long long maximumTotalCost(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size()+1,vector<long long>(2,0));
        for(int index = nums.size()-1;index>=0;index--)
        {
            for(int coeff = 0;coeff<2;coeff++)
            {
                long long x = nums[index];
                if(coeff == 0)
                    x = -x;
                long long subArr = x + dp[index+1][!coeff];
                long long startSub = nums[index] + dp[index+1][0];

                dp[index][coeff] = max(subArr,startSub);
            }
        }
        return dp[0][1];
    }
};