class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size()<=1)
            return strs[0];

        string ans="";

        int j=0;
        while(1)
        {
            for(int i=0;i<strs.size()-1;i++)
            {
                if(strs[i][j] != strs[i+1][j] || strs[i][j] == '\0' )
                {
                    return ans;
                }
            }
            ans += strs[0][j];
            j++;
        }
        
    }
};