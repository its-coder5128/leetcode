class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                    // dist[i][j] = 0;
                }
                else{
                    mat[i][j] = INT_MAX;
                }
            }
        }
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++)
            {
                int row = r + dRow[i];
                int col = c + dCol[i];

                if(row >= 0 && col >= 0 && row < n && col < m && mat[row][col] > mat[r][c] + 1)
                {
                    mat[row][col] = mat[r][c] + 1;
                    q.push({row,col});
                }
            }

        }

        return mat;
    }
};