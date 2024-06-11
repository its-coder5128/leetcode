class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev = matrix[0];
        vector<int> curr(m,INT_MAX);

        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                curr[j] = INT_MAX;

                int f = INT_MAX;
                if(j>0)
                    f = prev[j-1];
                int s = prev[j];
                int t = INT_MAX;
                if(j<m-1)
                    t = prev[j+1];
                
                curr[j] = matrix[i][j] + min({curr[j],f,s,t});
            }
            prev = curr;
        }

        return *min_element(prev.begin(),prev.end());
        
    }
};