class Solution {
public:
    bool isPali(string& str,int s,int e)
    {
        while(s<=e)
        {
            if(str[s] == str[e])
            {
                s++;
                e--;
            }
            else 
                return false;
        }

        return true;
    }
    int minCut(string str) {
        int n = str.size();
        vector<int> dp(n+1,0);

        for(int  s = n-1;s>=0;s--)
        {
            int mini = 1e9;
            for(int i = s;i<str.size();i++)
            {
                int ways = 1e9;
                if(isPali(str,s,i))
                    ways = 1 + dp[i+1];
                mini = min(ways,mini);
            }

            dp[s] = mini;
        }
        return dp[0] - 1;
    }
};