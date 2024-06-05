class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        if(n == 1 && m == 1)
            return 0;
        
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        vis[0][0] = 1;

        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};

        while(!q.empty())
        {
            int effort = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();

            if(r == n - 1 && c == m - 1)
                return effort;

            for(int i = 0;i<4;i++)
            {
                int nr = r + dRow[i];
                int nc = c + dCol[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m)
                {
                    int maxEffort = max(effort,abs(heights[r][c] - heights[nr][nc]));
                    if(vis[nr][nc] > maxEffort)
                    {
                        vis[nr][nc] = maxEffort;
                        q.push({maxEffort,{nr,nc}});
                    }
                }
                
            }
        }

        return vis[n-1][m-1];
    }
};