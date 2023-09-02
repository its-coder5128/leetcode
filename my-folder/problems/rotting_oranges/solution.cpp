class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;
        queue<pair<int,int>> q;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                    cnt++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        vector<int> row={-1,0,1,0};
        vector<int> col={0,1,0,-1};
        int n=q.size();
        int ans = 0;
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();

            if(n-- == 0)
            {
                ans++;
                n=q.size();
            }
            

            for(int i=0;i<4;i++)
            {
                int r = temp.first + row[i];
                int c = temp.second + col[i];

                if(r>=0 && r<grid.size() &&  c>=0 && c<grid[0].size() && grid[r][c] == 1)
                {
                    grid[r][c] = 2;
                    cnt--;
                    q.push({r,c});
                }
                
            }
        }

        if(cnt)
            return -1;
        
        return ans;
    }
};