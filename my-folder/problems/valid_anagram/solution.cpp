class Solution {
public:
    bool isAnagram(string s, string t) {

        int n = s.size();
        int m = t.size();
        
        if(n!=m)
            return false;

        vector<int> charSet1(26,0);
        vector<int> charSet2(26,0);

        for(int i = 0;i<n;i++)
        {
            int x = s[i] - 'a';
            int y = t[i] - 'a';

            charSet1[x]++;
            charSet2[y]++;
        }

        for(int i = 0;i<26;i++)
        {
            if(charSet1[i] != charSet2[i])
                return false;
        }

        return true;

    }
};