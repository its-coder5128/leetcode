class Solution {
public:
    bool check(vector<int>& arr)
    {
        int x = 0;
        bool flag = false;
        
        for(int i = 0;i<26;i++)
        {
            if(arr[i] != 0)
            {
                if(!flag)
                {
                    flag = true;
                    x = arr[i];
                }
                else if(arr[i] != x)
                    return false;
            }
        }
        
        return true;
    }
    int solve(string s,int index,vector<int> &dp)
    {
        int n = s.size();
        if(index == n)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        int ans = INT_MAX;
        vector<int> charSet(26,0);
        
        for(int i = index;i<n;i++)
        {
            charSet[s[i] - 'a']++;
            if(check(charSet))
                ans = min(ans,1 + solve(s,i+1,dp));
        }
        
        return dp[index] = ans;
    }
    int minimumSubstringsInPartition(string s) {
        vector<int> dp(s.size(),-1);
        return solve(s,0,dp);
    }
};