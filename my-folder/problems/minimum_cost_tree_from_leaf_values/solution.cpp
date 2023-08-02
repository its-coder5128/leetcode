class Solution {
public:

    
    int maxi(vector<int>& arr,int s,int e)
    {
        // if(dp1[s][e] != -1)
        //     return dp1[s][e];
        int ans=INT_MIN;

        for(int i=s;i<=e;i++)
        {
            ans = max(ans,arr[i]);
        }
        //dp1[s][e] = ans;
        return ans;
    }
    int solve(vector<int>& arr,int s,int e,vector<vector<int>> &dp)
    {
        if(s>=e)
            return 0;
        
        if(dp[s][e] != -1)
            return dp[s][e];
        
        int ans = INT_MAX;

        for(int i=s;i<e;i++)
        {
            ans = min(ans , maxi(arr,s,i)*maxi(arr,i+1,e) + solve(arr,s,i,dp) + solve(arr,i+1,e,dp));
        }

        return dp[s][e] = ans;

    }
    int solveTab(vector<int>& arr,int n)
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        //vector<vector<int>> dp1(n+1,vector<int>(n+1,-1));

        for(int s=n-1;s>=0;s--)
        {
            for(int e=s+1;e<n;e++)
            {
                int ans = INT_MAX;

                for(int i=s;i<e;i++)
                {
                    ans = min(ans , maxi(arr,s,i)*maxi(arr,i+1,e) + dp[s][i] + dp[i+1][e]);
                }

                dp[s][e] = ans;
            }
        }
        return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // vector<vector<int>> dp1(n+1,vector<int>(n+1,-1));

        // return solve(arr,0,n-1,dp,dp1);
        return solveTab(arr,n);

        
    }
};