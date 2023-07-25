class Solution {
public:
    int solve(vector<int>& obstacles,int index,int lane,vector<vector<int>> &dp)
    {
        if(index == obstacles.size()-1)
        {
            return 0;
        }

        if(dp[index][lane] != -1)
        {
            return dp[index][lane];
        }

        int ans=INT_MAX;
        if( lane == obstacles[index + 1] )
        {
            for(int i=1;i<=3;i++)
            {
                if( i != lane && obstacles[index] != i)
                {
                    ans =min(ans, 1 + solve(obstacles,index,i,dp) );
                }
            }

        }
        else{
            ans = 0 + solve(obstacles,index+1,lane,dp);
        }

        dp[index][lane] = ans;

        return dp[index][lane];
    }
    int minSideJumps(vector<int>& obstacles) {

        // int n=obstacles.size();
        // vector<vector<int>> dp(n,vector<int>(4,-1));
        // return solve(obstacles,0,2,dp);

        int n=obstacles.size();
        //vector<vector<int>> dp(n,vector<int>(4,1e9));

        // dp[n-1][0]=0;
        // dp[n-1][1]=0;
        // dp[n-1][2]=0;
        // dp[n-1][3]=0;
        vector<int> curr(4,1e9);
        vector<int> next(4,0);

        for(int index = n-2;index>=0;index--)
        {
            for(int lane=1;lane<=3;lane++)
            {
                int ans=1e9;
                if( lane == obstacles[index + 1] )
                {
                    for(int i=1;i<=3;i++)
                    {
                        if( i != lane && obstacles[index] != i)
                        {
                            ans =min(ans, 1 + next[i] );
                        }
                    }

                }
                else{
                    ans = 0 + next[lane];
                }

                curr[lane] = ans;
            }
            next=curr;
        }
        

        return min(curr[2],min(curr[1] + 1,curr[3] + 1));


        
    }
};