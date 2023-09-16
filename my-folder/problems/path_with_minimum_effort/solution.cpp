class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> visited(n,vector<int>(m,1e6));

        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        q.push({0,0,0,0});

        while(!q.empty())
        {
            auto t = q.top();
            q.pop();

            int i = t[1];
            int j = t[2];
            int cost = t[0];

            if(i == n-1 && j == m-1)
                return t[3];

            for(int k=0;k<4;k++)
            {
                int r = i + row[k];
                int c = j + col[k];

                if(r<0 || c<0 || r>=n || c>=m)
                    continue; 

                int toGo = abs(heights[r][c] - heights[i][j]);
                int maxi = max(t[3],toGo);

                if( visited[r][c] <= maxi)
                    continue;

                visited[r][c] = maxi;
                q.push({toGo,r,c,maxi});
            }
        }

        return -1;
    }
};