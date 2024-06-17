class Solution {
public:
    int solve(vector<int>& cuts,int s,int e,vector<vector<int>>& dp)
    {
        if(s>e) return 0;
        if(dp[s][e] != -1)
            return dp[s][e];

        int mini = 1e9;

        for(int i = s;i<=e;i++)
        {
            int cost = cuts[e+1] - cuts[s-1] + solve(cuts,s,i-1,dp) + solve(cuts,i+1,e,dp);
            mini = min(cost,mini);
        }

        return dp[s][e] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        n = cuts.size();

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int s = n-2;s>=1;s--)
        {
            for(int e = s;e<n-1;e++)
            {
                int mini = 1e9;

                for(int i = s;i<=e;i++)
                {
                    int cost = cuts[e+1] - cuts[s-1] + dp[s][i-1] + dp[i+1][e];
                    mini = min(cost,mini);
                }

                dp[s][e] = mini;
            }
        }
        return dp[1][n-2];
    }
};