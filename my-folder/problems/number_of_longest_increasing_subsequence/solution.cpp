class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> cnt(n,1);
        vector<int> dp(n,1);
        int maxi = 0;

        for(int i = 0;i<n;i++)
        {
            for(int prev = 0;prev<i;prev++)
            {
                if(nums[i] > nums[prev] && dp[i] < dp[prev] + 1)
                {
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev];
                }
                else if(nums[i] > nums[prev] && dp[i] == dp[prev]+1)
                {
                    cnt[i] += cnt[prev];
                }
            }
            if(maxi < dp[i])
            {
                maxi = dp[i];
            }
        }

        int count = 0;

        for(int i= 0;i<n;i++)
        {
            if(dp[i] == maxi)   count += cnt[i];
        }

        return count;
    }
};