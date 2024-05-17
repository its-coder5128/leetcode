class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();
        int m = strs[0].size();

        string ans = "";
        for(int j = 0;j<m;j++)
        {
            for(int i = 0;i<n-1;i++)
            {
                if(strs[i][j] == '\0' || strs[i+1][j] == '\0' || strs[i][j] != strs[i+1][j])
                    return ans;
                

            }
                ans += strs[0][j];
            
        }

        return ans;
        
    }
};