class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<int> row{-1,0,1,0};
        vector<int> col{0,1,0,-1};

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                    q.push({i,j});
                else
                    mat[i][j] = -1;               
            }
        }

        while(!q.empty())
        {
            auto [i,j] = q.front();
            q.pop();

            for(int k = 0;k<4;k++)
            {
                int nr = i + row[k];
                int nc = j + col[k];

                if( nr < 0 || nc < 0 || nr>=n || nc>=m || mat[nr][nc] != -1)
                    continue;
                else
                {
                    //cout<<nr<<" "<<nc<<endl;
                    mat[nr][nc] = 1+mat[i][j];
                }
                
                q.push({nr,nc});
            }
        }

        return mat;
        
    }
};