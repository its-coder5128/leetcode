class Solution {
public:
    static bool cmp(string& s1,string& s2)
    {
        int n = s1.size();
        int m = s2.size();
        return n<m;
    }
    bool isPossible(string s1,string s2)
    {
        int n = s1.size();
        int m = s2.size();

        if(n != m-1)
            return false;
        
        int cnt = 0;

        int i = 0;
        int j = 0;

        while(i<n && j<m)
        {
            if(s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else{
                cnt++;
                j++;
            }
        }

        if(i == n)
            return true;

        return cnt == 1;
        
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        // vector<pair<int,string>> list;
        // for(auto it:words)
        // {
        //     list.push_back({it.size(),it});
        // }
        sort(words.begin(),words.end(),cmp);
        // sort(list.begin(),list.end());
        vector<int> dp(n,1);

        int maxi = 0;

        for(int i = 0;i<n;i++)
        {
            string s1 = words[i];
            for(int prev = 0;prev<i;prev++)
            {
                string s2 = words[prev];

                if(isPossible(s2,s1) && dp[i] < dp[prev] + 1)
                    dp[i] = dp[prev] + 1;
            }
            maxi = max(maxi,dp[i]);
        }

        return maxi;
    }
};