class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0;
        int j = 0;

        for(int k=0;k<s.size();k++)
        {
            if(s[k] == '#')
            {
                i = max(0,--i);
            }
            else{
                s[i++] = s[k];
            }
        }
        for(int k=0;k<t.size();k++)
        {
            if(t[k] == '#')
            {
                j = max(0,--j);
            }
            else{
                t[j++] = t[k];
            }
        }

        if(j != i)
            return false;
        
        for(int k = 0;k<i;k++)
        {
            if(s[k] != t[k])
                return false;
        }
        return true;
        
    }
};