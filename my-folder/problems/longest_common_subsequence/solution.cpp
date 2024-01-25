class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        vector<int> curr(text2.size()+1,0);
        vector<int> next(text2.size()+1,0);

        for(int i = text1.size()-1;i>=0;i--)
        {
            for(int j = text2.size()-1;j>=0;j--)
            {
                int f1 = 0;
                if(text1[i] == text2[j])
                    f1 = 1 + next[j+1];
                
                int f2 = max(curr[j+1],max(next[j+1],next[j]));

                curr[j] = max(f1,f2);
            }
            next = curr;
        }

        return curr[0];
    }
};