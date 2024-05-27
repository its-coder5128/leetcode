class Solution {
public:
    bool solve(string &s,unordered_set<string> &st,int index,vector<int> &dp)
    {
        if(index == s.size())
            return true;
        if(dp[index] != -1)
            return dp[index];
        
        string temp = "";
        for(int i = index;i<s.size();i++)
        {
            temp += s[i];
            if(st.find(temp) != st.end() && solve(s,st,i+1,dp))
                return dp[index] = true;
        }

        return dp[index] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        unordered_set<string> st;

        for(auto it:wordDict)
            st.insert(it);
        
        return solve(s,st,0,dp);
    }
};