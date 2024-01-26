class Solution {
public:
    int solve(int m,int n,int k,int i,int j,vector<vector<vector<int>>>& dp)
    {
        if(i<0 || j<0 || i>=m || j>=n)
            return 1;
        if(k <= 0)
            return 0;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        int mod = 1e9 + 7;

        long long left = solve(m,n,k-1,i,j-1,dp)%mod;
        long long right = solve(m,n,k-1,i,j+1,dp)%mod;
        long long up = solve(m,n,k-1,i-1,j,dp)%mod;
        long long down = solve(m,n,k-1,i+1,j,dp)%mod;

        return dp[i][j][k] = (left+right+up+down)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn,dp);
    }
};