class Solution {
public:
    int solve(int i,int j,vector<vector<char>>& mat,vector<vector<int>> &vis,int &maxi)
    {
        if(i >= mat.size() || j>= mat[0].size() || mat[i][j] == '0')
            return 0;
        if(vis[i][j] != -1)
            return vis[i][j];

        vis[i][j] = 1 + min(solve(i,j+1,mat,vis,maxi),min(solve(i+1,j+1,mat,vis,maxi),solve(i+1,j,mat,vis,maxi)));
        maxi = max(maxi,vis[i][j]);
        return vis[i][j];
    }
    int maximalSquare(vector<vector<char>>& mat) {
        vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),-1));

        int maxi = INT_MIN;

        for(int i = 0;i<mat.size();i++)
        {
            for(int j = 0;j<mat[0].size();j++)
            {   
                maxi = max(maxi,solve(i,j,mat,vis,maxi));
            }
        }

        if(maxi == INT_MIN)
            return 0;
        return maxi*maxi;        
    }
};