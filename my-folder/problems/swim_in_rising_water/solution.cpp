class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0,grid[0][0]});

        vector<vector<int>> vis(n,vector<int>(m,0));

        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int time = it[0];
            int r = it[1];
            int c = it[2];
            int maxTime = it[3];
            
            if(r == n-1 && c == n -1)
                return maxTime;
            // cout<<time<<" "<<r<<" "<<c<<" "<<maxTime<<endl;

            if(vis[r][c] == 1)
                continue;
            
            vis[r][c] = 1;

            
            for(int i =0;i<4;i++)
            {
                int nr = r + dRow[i];
                int nc = c + dCol[i];
                // cout<<nr<<" "<<nc<<endl;

                if(nr >= 0 && nc >= 0 && nc < m && nr < n && vis[nr][nc] == 0)
                {
                    pq.push({grid[nr][nc],nr,nc,max(maxTime,grid[nr][nc])});
                }
            }
        }

        return -1;
        
    }
};