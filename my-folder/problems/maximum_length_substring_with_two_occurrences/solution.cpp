class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxi = INT_MIN;
        
        for(int i = 0;i<s.size();i++)
        {
            vector<int> charSet(26,0);
            for(int j=i;j<s.size();j++)
            {
                charSet[s[j] - 'a']++;
                if(charSet[s[j] - 'a'] == 3)
                {
                    break;
                }
                maxi = max(maxi,j-i+1);
            }
        }
        
        return maxi;
    }
};