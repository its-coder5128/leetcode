class Solution {
public:
    const int mod = 1000000007;
    int solve(int index,int n,int k ,int tar,vector<vector<int>> &dp)
    {
        if(index == n)
            return tar == 0;
        if(tar<0)
            return 0;
        if(dp[index][tar] != -1)
            return dp[index][tar];
        
        int ans = 0;
        
        for(int j=1;j<=k;j++)
        {
            ans = (ans + solve(index+1,n,k,tar-j,dp)) % mod;
        }
        
        return dp[index][tar] = ans%mod;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        

        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

        return solve(0,n,k,target,dp)%mod;
        
    }
};