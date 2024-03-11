class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> charSet(26,0);

        for(int i = 0;i<s.size();i++)
        {
            charSet[s[i] - 'a']++;
        }

        string ans = "";

        for(int j = 0;j<order.size();j++)
        {
            while(charSet[order[j] - 'a'])
            {
                ans += order[j];
                charSet[order[j] - 'a']--;
            }
        }

        for(int i = 0;i<26;i++)
        {
            while(charSet[i])
            {
                ans += i + 'a';
                charSet[i]--;
            }
        }

        return ans;
    }
};