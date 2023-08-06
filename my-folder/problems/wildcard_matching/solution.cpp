class Solution {
public:
    bool solve(string &s, string &p,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 && j<0)
            return true;
        if(i>=0 && j<0)
            return false;
        if(i<0 && j>=0)
        {
            for(int k=0;k<=j;k++)
            {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }
        if(dp[i][j] != -1)
            return dp[i][j];

        bool flag = false;
        if( s[i]==p[j] || p[j] == '?')
            flag = solve(s,p,i-1,j-1,dp);
        else if(p[j] == '*')
            flag = ( solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp) );
        else
            flag = false;
        
        dp[i][j] = flag;
        return flag;
    }
    bool solveTab(string &s, string &p)
    {
        //vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,0));

        vector<int> curr(p.length()+1,0);
        vector<int> prev(p.length()+1,0);

        prev[0] = 1;

        for(int j=1;j<=p.length();j++)
        {
            bool flag = true;
            for(int k=1;k<=j;k++)
            {
                if(p[k-1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=p.length();j++)
            {
                bool flag = false;

                if( s[i-1]==p[j-1] || p[j-1] == '?')
                    flag = prev[j-1];
                else if(p[j-1] == '*')
                    flag = ( prev[j] || curr[j-1] );
                else
                    flag = false;
                
                curr[j] = flag;
            }

            prev = curr;
        }
        
        return prev[p.length()];
    }
    bool isMatch(string s, string p) {

        // vector<vector<int>> dp(s.length(),vector<int>(p.length(),-1));
        
        // return solve(s,p,s.length()-1,p.length()-1,dp);

        return solveTab(s,p);
    }
};