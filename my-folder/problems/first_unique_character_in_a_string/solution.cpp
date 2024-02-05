class Solution {
public:
    int firstUniqChar(string s) {

        vector<int> charSet(26,0);

        for(auto i:s)
        {
            charSet[i - 'a']++;
        }

        for(int i = 0;i<s.size();i++)
        {
            if(charSet[s[i] - 'a'] == 1)
                return i;
        }

        return -1;

        
    }
};