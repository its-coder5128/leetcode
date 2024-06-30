class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;
        
        vector<vector<int>> dp(k,vector<int>(n,0));
        
        for(int i = n - 1;i>=0;i--)
        {
            int maxi = 0;
            for(int j = i + 1;j<n;j++)
            {
                int x = (nums[i] + nums[j])%k;
                
                maxi = dp[x][j];
                
                dp[x][i] = max(dp[x][i],maxi + 1);
                
                ans = max(maxi+1,ans);
            }
        }
        
        return ans+1;
    }
};