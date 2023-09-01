class Solution {
public:
    bool canTake(string s,int k,int i,int j)
    {
        long long num = stol(s.substr(i,j-i+1));

        if(num <=k && num>=1)
            return true;
        
        return false;
    }
    int solve(string &s,int k,int i,vector<int> &dp)
    {
        if(i == s.size())
            return 1;
        if(s[i] == '0')
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        int ans = 0;

        for(int j = i; j<s.size(); j++)
        {
            if(!canTake(s,k,i,j))
            {
                break;
            }
            
            ans = (ans + solve(s,k,j+1,dp)) % 1000000007;
        }

        return dp[i] = ans;

        
    }
    int numberOfArrays(string s, int k) {

        vector<int> dp(s.size()+1,0);

        int next = 1;
        int curr;

        dp[s.size()] = 1;

        for(int i = s.size()-1;i>=0;i--)
        {
            long num = 0;
            int ans = 0;
            if(s[i] == '0')
                continue;
            for(int j = i; j<s.size(); j++)
            {
                num = 10*num + s[j] - '0';

                if(!(num<=k && num>=1))
                {
                    break;
                }
                
                ans = (ans + dp[j+1]) % 1000000007;
            }

            dp[i] = ans;
        }

        return dp[0];
        
    }

};