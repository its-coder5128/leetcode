class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp = matrix;

        int count = 0;

        for(int i =1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j] == 1)
                {
                    dp[i][j] = 1 + min( { dp[i-1][j] , dp[i-1][j-1] , dp[i][j-1] } );
                }
            }
        }

        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                count += dp[i][j];
            }
        }
       

        return count;
    }
};