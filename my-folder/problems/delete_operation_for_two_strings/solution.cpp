class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(2,vector<int>(m+1,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1]) dp[1][j] = 1 + dp[0][j-1];
                else dp[1][j] = max(dp[0][j],dp[1][j-1]);
            }
            dp[0] = dp[1];
        }
        int len = dp[0][m];
        int ans = n + m - 2 * len;

        return ans;
    }
};