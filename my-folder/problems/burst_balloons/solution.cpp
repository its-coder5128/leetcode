class Solution {
public:
    int solve(vector<int>& nums,int s,int e)
    {
        if(s>e) return 0;

        int maxi = -1e8;

        for(int i = s;i<=e;i++)
        {
            int coins = nums[s-1] * nums[i] * nums[e+1] + solve(nums,s,i-1) + solve(nums,i+1,e);

            maxi = max(maxi,coins); 
        }

        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();

        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int s = n-2;s>=1;s--)
        {
            for(int e = s;e<n-1;e++)
            {
                int maxi = -1e8;

                for(int i = s;i<=e;i++)
                {
                    int coins = nums[s-1] * nums[i] * nums[e+1] + dp[s][i-1] + dp[i+1][e];

                    maxi = max(maxi,coins); 
                }

                dp[s][e] = maxi;
            }
        }
        return dp[1][n-2];
    }
};