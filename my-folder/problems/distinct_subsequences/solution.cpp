class Solution {
public:
    int solve(string& s,string& t,int n,int m,vector<vector<int>>& dp)
    {
        if(n == 0 || m == 0)
            return m == 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(s[n-1] == t[m-1])
            return dp[n][m] =  solve(s,t,n-1,m-1,dp) + solve(s,t,n-1,m,dp);
        else 
            return dp[n][m] = solve(s,t,n-1,m,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        int MOD = 1e9+7;

        if(m > n)
            return 0;
        
        vector<int> curr(m+1,0);
        
        curr[0] = 1;
        
        for(int i = 1;i<=n;i++)
        {
            for(int j = m;j>0;j--)
            {
                if(s[i-1] == t[j-1])
                    curr[j] = (curr[j-1] % MOD + curr[j]%MOD)%MOD;
                else
                    curr[j] = curr[j];
            }
        }
            
        return curr[m];
        
    }
};