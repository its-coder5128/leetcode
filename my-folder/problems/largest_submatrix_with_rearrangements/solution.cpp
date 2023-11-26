class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {

        for(int i = 1;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 1)
                {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 0;i<matrix.size();i++)
        {
            sort(matrix[i].begin(),matrix[i].end(),greater<int>());
            for(int j = 0;j<matrix[0].size();j++)
            {
                maxi = max(maxi,matrix[i][j]*(j+1));
            }
        }

        return maxi;
    }
};