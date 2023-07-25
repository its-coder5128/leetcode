class Solution {
public:
    int solve(vector<int>& satisfaction,int index,int timer,vector<vector<int>> &dp)
    {
        if(index == satisfaction.size())
        {
            return 0;
        }

        if(dp[index][timer] != -1)
            return dp[index][timer];

        int exclude = solve(satisfaction,index + 1,timer,dp);

        int include = satisfaction[index]*(timer + 1) + solve(satisfaction,index+1,timer+1,dp);

        dp[index][timer] = max(include,exclude);

        return dp[index][timer];
    }
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(),satisfaction.end());

        // for(int i=0;i<satisfaction.size();i++)
        // {
        //     cout<<satisfaction[i]<<" , ";
        // }
        int n = satisfaction.size();
        //vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> curr(n+1,0);
       // vector<int> next(n+1,0);

        // for(int i=0;i<n;i++)
        // {
        //     dp[n][i]=0;
        //     dp[i][n]=0;
        // }

        // int timer=0;
        //int index=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int timer=0;timer<n;timer++)
            {
                int exclude = curr[timer];

                int include = satisfaction[index]*(timer + 1) + curr[timer+1];

                curr[timer] = max(include,exclude);
            }
            //next=curr;

        }

        return curr[0];
    
    }
};