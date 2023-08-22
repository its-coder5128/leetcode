class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        string s1 = s;

        for(int i = 0;i<s.size()/2;i++)
        {
            s.push_back(s[0]);

            s.erase(0,1);

            if(s == s1)
                return true;

        }

        return false;
        
    }
};