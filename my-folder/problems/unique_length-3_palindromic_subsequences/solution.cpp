class Solution {
public:
    int countPalindromicSubsequence(string s) {

        unordered_map<char,int> left;
        unordered_map<char,int> right;

        left[s[0]]++;

        for(int i = 1;i<s.size();i++)
        {
            right[s[i]]++;
        }
        unordered_set<string> ans;
        for(int i = 1;i<s.size();i++)
        {
            right[s[i]]--;
            if(right[s[i]] == 0)
                right.erase(s[i]);
            for(auto str:left)
            {
                if(right.find(str.first) != right.end())
                {
                    string temp = "";
                    temp.push_back(str.first);
                    temp.push_back(s[i]);
                    temp.push_back(str.first);
                    ans.insert(temp);
                }
            }
            left[s[i]]++;
        }

        return ans.size();
        
    }
};