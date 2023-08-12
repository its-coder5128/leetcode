class Solution {
public:
    // bool safe(vector<vector<int>>& obstacleGrid,int i,int j,int n,int m)
    // {
    //     if(i<n && i>=0 && j<m && j>=0 &&  obstacleGrid[i][j] != 1)
    //         return true;
    //     return false;
    // }
    // int solve(vector<vector<int>>& obstacleGrid,int i,int j,int n,int m,vector<vector<int>> &dp)
    // {
    //     if(i == n-1 && j == m-1)
    //         return 1;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
        
    //     //int ans = 0;
    //     int down = 0;
    //     int right = 0;

    //     int newRow;
    //     int newCol;

    //     //down;
    //     newRow = i+1;
    //     newCol = j;

    //     if(safe(obstacleGrid,newRow,newCol,n,m))
    //     {
    //         down = solve(obstacleGrid,newRow,newCol,n,m,dp);
    //     }

    //     //right
    //     newRow = i;
    //     newCol = j+1;
        
    //     if(safe(obstacleGrid,newRow,newCol,n,m))
    //     {
    //         right = solve(obstacleGrid,newRow,newCol,n,m,dp);
    //     }
    //     dp[i][j] = down + right;

    //     return dp[i][j];

    // }
    // int solveTab(vector<vector<int>>& obstacleGrid,int n,int m)
    // {
    //     if(obstacleGrid[m-1][n-1]==1 ||obstacleGrid[0][0]==1 ) return 0;
    //     vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
    //     dp[n-1][m-1] = 1;

    //     for(int i=n-1;i>=0;i--)
    //     {
    //         for(int j=m-1;j>=0;j--)
    //         {
    //             if(i == n-1 && j == m-1)
    //                 continue;
    //             if(obstacleGrid[i][j]==1) dp[i][j]=0;
    //             else{
    //                 long long down = 0;
    //                 long long right = 0;

    //                 if(i+1 < n )
    //                     down = dp[i+1][j];
    //                 if(j+1 < m )
    //                     right = dp[i][j+1];

    //                 dp[i][j] = down + right;
    //             }
               
    //         }
    //     }

    //     return dp[0][0];
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[n-1][m-1]==1 ||obstacleGrid[0][0]==1 ) 
            return 0;

        //vector<vector<long long>> dp(n,vector<long long>(m,0));

        vector<long> curr(m,0);
        vector<long> next(m,0);
        curr[m-1] = 1;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i == n-1 && j == m-1)
                    continue;
                if(obstacleGrid[i][j]==1) curr[j]=0;
                else{
                    long long down = 0;
                    long long right = 0;

                    if(i+1 < n )
                        down = next[j];
                    if(j+1 < m )
                        right = curr[j+1];

                    curr[j] = down + right;
                }
               
            }
            next = curr;
        }

        return next[0];
    }
};