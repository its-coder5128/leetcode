class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;

        vector<vector<int>> dist(n,vector<int>(m,1e9));

        queue<pair<int,pair<int,int>>> q;

        q.push({1,{0,0}});

        int dRow[] = {-1,-1,-1,0,1,1,1,0};
        int dCol[] = {-1,0,1,1,1,0,-1,-1};

        dist[0][0] = 1;

        while(!q.empty())
        {
            int cost = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for(int i = 0;i<8;i++)
            {
                int nr = r + dRow[i];
                int nc = c + dCol[i];

                if(nc >= 0 && nr >= 0 && nc < m && nr < n && grid[nr][nc] == 0 && dist[nr][nc] > cost + 1)
                {
                    dist[nr][nc] = cost + 1;
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }

        if(dist[n-1][m-1] == 1e9)
            return -1;
        return dist[n-1][m-1];
    }
};