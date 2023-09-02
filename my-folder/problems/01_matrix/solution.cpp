class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                    q.push({i,j});
                else if(mat[i][j] == 1)
                    mat[i][j] = -1;
            }
        }

        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};

        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();

            int mini = INT_MAX;
            for(int i=0;i<4;i++)
            {

                int r = temp.first + row[i];
                int c = temp.second + col[i];

                if(r>=0 && c>=0 && r<n && c<m && mat[r][c] == -1)
                {
                    q.push({r,c});
                    mat[r][c] = 1 + mat[temp.first][temp.second];
                }
            }
        }

        return mat;
        
    }
};