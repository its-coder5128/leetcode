class Solution {
public:
    bool solve(string &s,vector<string>& wordDict,int i,vector<int> &dp)
    {
        if(i == s.size())
            return true;
        if(dp[i] != -1)
            return dp[i];

        bool ans = false;

        for(auto word:wordDict)
        {
            int j = word.size();

            if(i+j <= s.size() && s.substr(i,j) == word)
                ans = solve(s,wordDict,i+j,dp);
            if(ans)
                break;
        }

        dp[i] = false || ans;
        return false || ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // set<string> st;

        // for(int i=0;i<wordDict.size();i++)
        // {
        //     st.insert(wordDict[i]);
        // }
        
        vector<int> dp(s.size(),-1);
        return solve(s,wordDict,0,dp);
    }
};