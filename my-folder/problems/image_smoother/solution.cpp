class Solution {
public:
    bool check(int n,int m,int i,int j)
    {
        if(i>=0 && i<n && j>=0 && j<m)
            return true;
        
        return false;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int n = img.size();
        int m = img[0].size();
        
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                int sum = img[i][j];
                int cnt = 1;

                if(check(n,m,i-1,j-1)) 
                {
                    cnt++; 
                    sum += img[i-1][j-1];
                }
                if(check(n,m,i-1,j))
                {
                    cnt++; 
                    sum += img[i-1][j];
                } 
                if(check(n,m,i-1,j+1)) 
                {
                    cnt++; 
                    sum += img[i-1][j+1];
                } 
                if(check(n,m,i,j-1)) 
                {
                    cnt++; 
                    sum += img[i][j-1];
                } 
                if(check(n,m,i,j+1)) 
                {
                    cnt++; 
                    sum += img[i][j+1];
                } 
                if(check(n,m,i+1,j-1)) 
                {
                    cnt++; 
                    sum += img[i+1][j-1];
                } 
                if(check(n,m,i+1,j)) 
                {
                    cnt++; 
                    sum += img[i+1][j];
                } 
                if(check(n,m,i+1,j+1)) 
                {
                    cnt++; 
                    sum += img[i+1][j+1];
                } 

                ans[i][j] = sum/cnt;

            }
        }

        return ans;
        
    }
};