class Solution {
public:
    bool solve(string s1, string s2, string s3,int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(dp[i][j] != -1)
            return dp[i][j];

        if(i>=n && j>=m)
        {
            return dp[i][j]=true;
        }
        else if(i<n && s1[i] == s3[i+j] && j<m && s2[j] == s3[i+j] )
        {
            return dp[i][j]=solve(s1,s2,s3,i+1,j,n,m,dp) || solve(s1,s2,s3,i,j+1,n,m,dp);
        }
        else if(i<n && s1[i] == s3[i+j])
        {
            return dp[i][j]=solve(s1,s2,s3,i+1,j,n,m,dp);
        }
        else if(j<m && s2[j] == s3[i+j])
        {
            return dp[i][j]=solve(s1,s2,s3,i,j+1,n,m,dp);
        }
        else
            return dp[i][j]=false;

    }
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();
        int l = s3.size();

        if(l != m+n)
            return false;

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return solve(s1,s2,s3,0,0,n,m,dp);
        

        
    }
};