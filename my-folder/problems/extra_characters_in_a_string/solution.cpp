class Solution {
public:
    int solve(string &s, vector<string>& dict,int index,vector<int> &dp)
    {
        if(index == s.size())
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        int cnt = INT_MAX;

        for(auto i:dict)
        {
            int len = i.size();
            cout<<s.substr(index,len)<<endl;
            if(s.substr(index,len) == i)
                cnt = min(cnt,solve(s,dict,index+len,dp));
        }

        cnt = min(1+solve(s,dict,index+1,dp),cnt);

        return dp[index]=cnt;
    }
    int minExtraChar(string s, vector<string>& dict) {
        // vector<int> dp(s.size(),-1);
        // return solve(s,dictionary,0,dp);
        
        vector<int> dp(s.size()+1,0);

        for(int index = s.size()-1;index>=0;index--)
        {
            int cnt = INT_MAX;

            for(auto i:dict)
            {
                int len = i.size();
                //cout<<s.substr(index,len)<<endl;
                if(s.substr(index,len) == i && index+len<=s.size())
                    cnt = min(cnt,dp[index+len]);
            }

            cnt = min(1+dp[index+1],cnt);

            dp[index]=cnt;
        }

        return dp[0];
    }
};