class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxi = 0;
        int maxChar = 0;
        int n = s.size();
        unordered_map<int,int> m;

        while(r<n)
        {
            m[s[r]]++;
            maxChar = max(maxChar,m[s[r]]);

            if(r - l + 1 - maxChar > k)
            {
                m[s[l]]--;
                if(m[s[l]] == 0)
                    m.erase(s[l]);
                l++;
            }
            if(r - l + 1 - maxChar <= k)
                maxi = max(maxi,r-l+1);
            r++;
        }

        return maxi;
    }
};