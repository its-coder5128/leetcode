class Solution {
public:
    int solve(string s,int i,int j,vector<vector<int>> &dp)
    {
        if(i == j)
            return 1;
        if( i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;

        if(s[i] == s[j])
            ans = 2 + solve(s,i+1,j-1,dp);
        else
            ans = max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));

        dp[i][j] = ans;

        return ans;

    }
    int solveTab(string s)
    {
       //vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0)); 
       vector<int> curr(s.size()+1,0);
       vector<int> next(s.size()+1,0);
       
       for(int i=s.size()-1;i>=0;i--)
       {
            for(int j=i;j<s.size();j++)
           {
                if(i == j)
                    curr[j] = 1;
                else{
                    int ans = 0;

                    if(s[i] == s[j])
                        ans = 2 + next[j-1];
                    else
                        ans = max(next[j],curr[j-1]);

                    curr[j] = ans;
                }    
           }

           next = curr;
       }

       return next[s.size()-1];
    }
    int longestPalindromeSubseq(string s) {

        // vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));

        // return solve(s,0,s.size()-1,dp);

        if(s.size()<2)
            return s.size();

        return solveTab(s);
        
    }
};