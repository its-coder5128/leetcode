class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string str = "";

        int i = n;
        int j = m;

        while(i>0 && j>0)
        {
            if(s[i-1] == t[j-1])
            {
                str += s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                str += s[i-1];
                i--;
            }
            else 
            {
                str += t[j-1];
                j--;
            }
        }


        // i = 0;
        // j = 0;

        // string ans = "";

        // for(int k = 0;k<str.size();k++)
        // {
        //     while(i<n && s[i] != str[k])
        //     {
        //         ans += s[i];
        //         i++;
        //     }
        //     while(j<m && t[j] != str[k])
        //     {
        //         ans += t[j];
        //         j++;
        //     }
        //     ans += str[k];
        //     i++;
        //     j++;
        // }
        while(i>0)
        {
            str += s[i-1];
            i--;
        }
        while(j>0)
        {
            str += t[j-1];
            j--;
        }

        reverse(str.begin(),str.end());
        return str;
        
    }
};