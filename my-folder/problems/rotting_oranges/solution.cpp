class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row{-1,0,1,0};
        vector<int> col{0,1,0,-1};
        int cnt = 0;
        int time = 0;

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }

        while(!q.empty())
        {
            int qs = q.size();

            for(int i= 0;i<qs;i++)
            {
                auto front = q.front();
                q.pop();
                
                for(int j = 0;j<4;j++)
                {
                    int newRow = front.first + row[j];
                    int newCol = front.second + col[j];
                    if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && grid[newRow][newCol] == 1)
                    {
                        grid[newRow][newCol] = 2;
                        q.push({newRow,newCol});
                    }

                }
            }
            if(q.empty())
                break;
            cnt -= q.size();
            time++;
        }



        return cnt == 0 ? time : -1;
    }
};