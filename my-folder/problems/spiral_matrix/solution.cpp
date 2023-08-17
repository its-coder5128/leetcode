class Solution {
public:
    bool isSafe(vector<vector<int>>& visited,int i,int j)
    {
        if(i>=0 && j>= 0 && i<visited.size() && j<visited[0].size() && visited[i][j] == 0)
            return true;
        
        return false;
    }
    void rec(vector<vector<int>>& mat,vector<vector<int>>& visited,int i,int j,vector<int> &ans)
    {

        while(isSafe(visited,i,j))
        {
            visited[i][j] = 1;
            ans.push_back(mat[i][j]);
            j++;
        }
        i++;
        j--;
        while(isSafe(visited,i,j))
        {
            visited[i][j] = 1;
            ans.push_back(mat[i][j]);
            i++;
        }
        i--;
        j--;
        while(isSafe(visited,i,j))
        {
            visited[i][j] = 1;
            ans.push_back(mat[i][j]);
            j--;
        }
        j++;
        i--;
        while(isSafe(visited,i,j))
        {
            visited[i][j] = 1;
            ans.push_back(mat[i][j]);
            i--;
        }
        i++;
        j++;
        if(isSafe(visited,i,j))
            rec(mat,visited,i,j,ans);

    }
    vector<int> spiralOrder(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        vector<int> ans;

        rec(mat,visited,0,0,ans);

        return ans;
        
    }
};