class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        vector<vector<int>> dp = matrix;

        for(int j = 0;j<matrix[0].size();j++)
        {
            int sum = 0;
            for(int i = 0;i<matrix.size();i++)
            {
                sum += matrix[i][j];
                dp[i][j] = sum;
            }
        }
        int ans = 0;

        for(int r1=0;r1<dp.size();r1++)
        {
            for(int r2=r1;r2<dp.size();r2++)
            {
                int sum = 0;
                unordered_map<int,int> m;
                m[0] = 1;
                for(int c = 0;c<dp[0].size();c++)
                {
                    sum += dp[r2][c] - (r1>0?dp[r1-1][c]:0);
                    ans += m[sum-target];
                    m[sum]++;
                }
            }
        }

        return ans;
        
    }
};