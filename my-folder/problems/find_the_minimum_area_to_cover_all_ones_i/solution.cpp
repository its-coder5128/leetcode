class Solution {
public:
    int cntCol(vector<vector<int>>& grid,int n,int col)
    {
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            if(grid[i][col] == 1)
                cnt++;
        }
        
        return cnt;
    }
    int cntRow(vector<vector<int>>& grid,int row,int m)
    {
        int cnt = 0;
        for(int i = 0;i<m;i++)
        {
            if(grid[row][i] == 1)
                cnt++;
        }
        
        return cnt;
    }
    int minimumArea(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int row1 = 0;
        int row2 = n-1;
        int col1 = 0;
        int col2 = m-1;
        
        for(int i = 0;i<m;i++)
        {
            if(cntCol(grid,n,i) > 0)
                break;
            else
                col1++;
        }
        for(int i = m-1;i>=0;i--)
        {
            if(cntCol(grid,n,i) > 0)
                break;
            else
                col2--;
        }
         for(int i = 0;i<n;i++)
        {
            if(cntRow(grid,i,m) > 0)
                break;
            else
                row1++;
        }
        for(int i = n-1;i>=0;i--)
        {
            if(cntRow(grid,i,m) > 0)
                break;
            else
                row2--;
        }
        
        int area = (row2-row1+1) * (col2-col1+1);
        
        return area;
        
    }
};