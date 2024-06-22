class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> req(n,-1);
        for(auto it:requirements)
            req[it[0]] = it[1];
        
        vector<vector<int>> dp(n,vector<int>(405,0));

        long long MOD = 1e9 + 7;

        dp[0][0] = 1;

        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<405;j++)
            {
                if(req[i] != -1 && req[i] != j)
                    continue;
                long long cnt = 0;
                for(int k = max(0,j-i);k<=j;k++)
                {
                    cnt = (cnt + dp[i-1][k]) % MOD;
                }
                dp[i][j] = cnt;
            }
        }

        long long ans = 0;

        for(int i = 0;i<405;i++)
            ans  = (ans + dp[n-1][i])%MOD;
        
        return ans;
    }
};