class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> m;

        int l = 0;
        int r = 0;
        int n = s.size();
        int maxi = 0;

        while(r<n)
        {
            char c = s[r];

            if(m.find(c) != m.end() && l<=m[c])
            {
                l = m[c] + 1;
            }
            m[c] = r;

            maxi = max(maxi,r-l+1);
            r++;

        }

        return maxi;
        
    }
};