class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || j < 0 || grid[i][j] == 1)
            return 0;
        if(i == 0 && j == 0)
            return 1;
        
        return solve(grid,i-1,j) + solve(grid,i,j-1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1)
            return 0;
        vector<int> prev(m,0);

        for(int i = 0;i<n;i++)
        {
            vector<int> curr(m,0);
            if(i == 0)
                curr[0] = 1;
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1)
                    continue;
                
                if(i-1 >= 0)
                    curr[j] += prev[j];
                if(j-1 >= 0)
                    curr[j] += curr[j-1];
            }
            prev = curr;
        }

        return prev[m-1];


    }
};