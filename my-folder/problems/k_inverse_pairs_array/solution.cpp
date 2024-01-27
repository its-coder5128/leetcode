class Solution {
public:
    int solve(int n,int k,int index,vector<vector<int>>& dp)
    {
        if( k <= 0)
            return k==0;
        if(dp[index][k] != -1)
            return dp[index][k];
        
        int sum = 0;

        for(int i = index;i<n;i++)
        {
            sum += solve(n,k-i+index,index+1,dp); 
            sum %= 1000000007;        
        }

        return dp[index][k] = sum;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));

        for(int i = 0;i<=n;i++)
            dp[i][0] = 1;

        for(int i = n-1;i>=0;i--)
        {
            for(int j = 0;j<=k;j++)
            {
                int sum = 0;

                for(int index = i;index<n;index++)
                {
                    if(j+i-index >= 0)
                        sum += dp[i+1][j+i-index]; 
                    sum %= 1000000007;        
                }

                dp[i][j] = sum;
            }
        }
        return dp[0][k];
    }
};