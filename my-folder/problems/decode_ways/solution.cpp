class Solution {
public:
    int solve(string s,int index,int last,vector<vector<int>> &dp)
    {
        if(last <= 0 || last>26)
            return 0;
        if(index == s.size())
            return 1;
        if(dp[index][last] != -1)
            return dp[index][last];
        
        int mkGrp = solve(s,index+1,last*10 + (s[index]-'0'),dp);
        int notMkGrp = solve(s,index+1,s[index]-'0',dp);

        return dp[index][last] = mkGrp + notMkGrp;
    }
    int numDecodings(string s) {

        vector<vector<int>> dp(s.size(),vector<int>(27,-1));
        return solve(s,1,s[0]-'0',dp);
        
    }
};