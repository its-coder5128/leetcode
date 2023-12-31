class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        vector<int> mini(26,400);
        vector<int> maxi(26,-1);
        int ans = -1;

        for(int i = 0;i<s.size();i++)
        {
            mini[s[i] - 'a'] = min(mini[s[i] - 'a'],i);
            maxi[s[i] - 'a'] = max(maxi[s[i] - 'a'],i);
        }
        for(int i = 0;i<26;i++)
        {
            ans = max(ans,maxi[i] - mini[i] - 1);
        }
        
        return ans;
    }
};