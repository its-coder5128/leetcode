class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int cnt = 0;
        int l = 0;
        int r = 0;
        vector<int> m(3,0);

        while(r<n)
        {
            char c = s[r];

            m[c-'a']++;

            while(m[0] && m[1] && m[2])
            {
                cnt += n-r;
                m[s[l] - 'a']--;
                l++;
            }

            r++;
        }

        return cnt;
    }
};