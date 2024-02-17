class Solution {
public:
    string lastNonEmptyString(string s) {
        
        vector<int> charSet(26,0);
        
        int maxi = 0;
        
        for(auto c:s)
        {
            charSet[c - 'a']++;
            maxi = max(maxi,charSet[c-'a']);
        }
        
        string ans = "";
        
        for(int i = s.size()-1 ;i >= 0; i--)
        {
            char c = s[i];
            if(charSet[c - 'a'] == maxi)
            {
                ans += c;
                charSet[c - 'a'] = 0;
            }
                
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};