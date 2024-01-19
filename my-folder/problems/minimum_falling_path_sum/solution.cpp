class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        for(int i = 1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                int f = 1e9;
                int s = 1e9;
                int t = 1e9;

                if(j-1>=0)
                    f = matrix[i-1][j-1];
                s = matrix[i-1][j];
                if(j+1<matrix[0].size())
                    t = matrix[i-1][j+1];
                
                matrix[i][j] += min(f,min(s,t));
            }
        }

        int ans = INT_MAX;

        for(int i = 0;i<matrix[0].size();i++)
        {
            ans = min(ans,matrix[matrix.size()-1][i]);
        }

        return ans;
    }
};