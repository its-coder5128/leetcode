class Solution {
public:
    bool isPossible(string str,vector<int> m)
    {
        for(int i = 0;i<str.size();i++)
        {
            if(m[str[i]-'a'] > 0)
            {
                m[str[i]-'a']--;
            }
            else
                return false;
        }

        return true;
    }
    int countCharacters(vector<string>& words, string chars) {

        vector<int> m(26,0);

        for(auto i:chars)
            m[i-'a']++;

        int sum = 0;
        for(auto str:words)
        {
            if(isPossible(str,m))
                sum += str.size();
        }

        return sum;
        
    }
};