class Solution {
public:
    bool check(vector<vector<int>>& mat,int r,int c)
    {
        for(int i=0;i<mat[0].size();i++)
        {
            if(mat[r][i] == 1 && i!=c)
                return false;
        }
        for(int i=0;i<mat.size();i++)
        {
            if(mat[i][c] == 1 && i!=r)
                return false;
        }
        return true;
        
    }
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;

        for(int i = 0;i<mat.size();i++)
        {
            for(int j = 0;j<mat[0].size();j++)
            {
                if(mat[i][j] == 1 && check(mat,i,j))
                    cnt++;
            }
        }

        return cnt;
        
    }
};