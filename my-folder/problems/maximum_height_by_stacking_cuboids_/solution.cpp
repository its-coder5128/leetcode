class Solution {
public:
    bool check(vector<int> &a,vector<int> &b)
    {
        if(a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2])
            return true;
        else
            return false;
    }
    int solve(vector<vector<int>>& cuboids,int curr,int prev,vector<vector<int>>& dp)
    {
        if(curr == cuboids.size())
            return 0;
        
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        int include = 0;

        if(prev == -1 || check(cuboids[curr],cuboids[prev]))
            include = cuboids[curr][2] + solve(cuboids,curr+1,curr,dp);
        
        int exclude = 0 + solve(cuboids,curr + 1,prev,dp);

        dp[curr][prev+1] = max(include,exclude);

        return dp[curr][prev+1];
        
    } 
    int solveTab(vector<vector<int>>& cuboids,int n)
    {
        //vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> current(n+1,0);
        vector<int> next(n+1,0);

        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=n-2;prev>=-1;prev--)
            {
                int include = 0;

                if(prev == -1 || check(cuboids[curr],cuboids[prev]))
                    include = cuboids[curr][2] + next[curr+1];
                
                int exclude = 0 + next[prev+1];

                current[prev+1] = max(include,exclude);
            }
            next = current;
        }

        return next[0];


    }   
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &i:cuboids)
        {
            sort(i.begin(),i.end());
        }

        sort(cuboids.begin(),cuboids.end());

        // for(int i=0;i<cuboids.size();i++)
        // {
        //     cout<<cuboids[i][0]<<" , ";
        //     cout<<cuboids[i][1]<<" , ";
        //     cout<<cuboids[i][2]<<" , ";
        //     cout<<endl;
        // }
        int n=cuboids.size();

        //vector<vector<int>> dp(n,vector<int>(n+1,-1));

        //return solve(cuboids,0,-1,dp);
        return solveTab(cuboids,n);
        
    }
};