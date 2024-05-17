class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> charSet1(256,-1);
        vector<int> charSet2(256,-1);

        int n = s.size();

        for(int i = 0;i<n;i++)
        {
            int x = s[i];
            int y = t[i];
            if(charSet1[x] != -1 && charSet1[x] != y)
                return false;
            else if(charSet2[y] != -1 && charSet2[y] != x)
                return false;
            
            charSet1[x] = y;
            charSet2[y] = x;
            
        }

        return true;
    }
};