class Solution {
public:
    int solve(string& s,int i,int j,vector<vector<int>>& dp)
    {
        if(j <= i )
            return i==j;
        if(dp[i][j] != -1)
            return dp[i][j]; 
        
        if(s[i] == s[j])
            return dp[i][j] = 2 + solve(s,i+1,j-1,dp);
        else{
            return dp[i][j] = max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
        }
            
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0;i<n;i++)  dp[i][i] = 1;

        for(int i = n-1;i>=0;i--)
        {
            for(int j = i+1;j<n;j++)
            {
                if(s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};