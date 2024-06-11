class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> next = triangle[n-1];

        for(int i = n-2;i>=0;i--)
        {
            vector<int> curr(i+1,0);
            for(int j = 0;j<=i;j++)
            {
                curr[j] = triangle[i][j] + min(next[j],next[j+1]);
            }

            next = curr;
        }

        return next[0];
    }
};