class Solution {
public:
    int solve(string& word1,string& word2,int n,int m,vector<vector<int>>& dp)
    {
        if(n == 0 && m == 0)
            return 0;
        if(m == 0)
            return n;
        if(n == 0)
            return m;
        if(dp[n][m] != -1)
            return dp[n][m];
        
        int maxi = -1e8;

        if(word1[n-1] == word2[m-1])
            return dp[n][m] = solve(word1,word2,n-1,m-1,dp);
        else
        {
            maxi = min({1 + solve(word1,word2,n,m-1,dp),1 + solve(word1,word2,n-1,m,dp),1 + solve(word1,word2,n-1,m-1,dp)});
            return dp[n][m] = maxi;
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++) dp[i][0] = i;
        for(int i = 1;i<=m;i++) dp[0][i] = i;

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
            }
        }
        return dp[n][m];
    }
};