class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        vector<int> dp(target+1,0);
        dp[0] = 1;

        for(int i = 1;i<=target;i++)
        {
            long long ans = 0;

            for(int j = 0;j<nums.size();j++)
            {
                if(i - nums[j] >= 0)
                    ans += dp[i - nums[j]];
                else
                    ans += 0;
            }

            dp[i] = ans;
        }

        return dp[target];
        
    }
};