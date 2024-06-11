class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m,INT_MAX);

        for(int i = 0;i<n;i++)
        {
            vector<int> curr(m,INT_MAX);
            for(int j = 0;j<m;j++)
            {
                if(i == 0 && j == 0)
                    curr[j] = grid[i][j];
                else{
                    if(i>0)
                        curr[j] = min(curr[j],grid[i][j]+prev[j]);
                    if(j>0)
                        curr[j] = min(curr[j],grid[i][j]+curr[j-1]);
                }
            }

            prev = curr;
        }

        return prev[m-1];
        
    }
};