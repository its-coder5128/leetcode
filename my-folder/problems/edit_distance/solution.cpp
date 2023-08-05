class Solution {
public:
    int solve(string word1, string word2,int i,int j,vector<vector<int>> &dp)
    {
        if(i == word1.size())
        {
            return word2.size() - j;
        }
        if(j == word2.size())
        {
            return word1.size() - i;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;

        if(word1[i] == word2[j])
            ans = solve(word1,word2,i+1,j+1,dp);
        else
        {
            int ins = 1 + solve(word1,word2,i,j+1,dp);
            int del = 1 + solve(word1,word2,i+1,j,dp);
            int rep = 1 + solve(word1,word2,i+1,j+1,dp);

            ans = min(ins,min(del,rep));
        }

        dp[i][j] = ans;

        return ans;
    }
    int solveTab(string word1, string word2)
    {
        //vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        vector<int> curr(word2.size()+1,0);
        vector<int> next(word2.size()+1,0);

        for(int i=word1.size();i>=0;i--)
        {
            for(int j=word2.size();j>=0;j--)
            {
                if(i == word1.size())
                {
                    curr[j] = word2.size() - j;
                }
                else if(j == word2.size())
                {
                    curr[j] = word1.size() - i;
                }
                else{
                    int ans = 0;

                    if(word1[i] == word2[j])
                        ans = next[j+1];
                    else
                    {
                        int ins = 1 + curr[j+1];
                        int del = 1 + next[j];
                        int rep = 1 + next[j+1];

                        ans = min(ins,min(del,rep));
                    }

                    curr[j] = ans;
                }
            }

            next = curr;

        }

            return curr[0];


    }
    int minDistance(string word1, string word2) {

        // vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));

        // return solve(word1,word2,0,0,dp);
        return solveTab(word1,word2);
    }
};