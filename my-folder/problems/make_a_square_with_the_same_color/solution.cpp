class Solution {
public:
    bool square(vector<vector<char>>& grid,int i,int j)
    {
        int w = 0;
        int b = 0;
        
        if(grid[i][j] == 'W')
            w++;
        else
            b++;
        if(grid[i+1][j] == 'W')
            w++;
        else
            b++;
        if(grid[i][j+1] == 'W')
            w++;
        else
            b++;
        if(grid[i+1][j+1] == 'W')
            w++;
        else
            b++;
        
        return w<=1 || b<=1;
    }
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i = 0;i<grid.size()-1;i++)
        {
            for(int j = 0;j<grid[0].size()-1;j++)
            {
                if(square(grid,i,j))
                    return true;
            }
        }
        
        return false;
        
    }
};