class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        vector<int> curr(triangle.size()+1,0);
        vector<int> next(triangle.size()+1,0);

        for(int i = triangle.size()-1;i>=1;i--)
        {
            for(int j = 0;j<i;j++)
            {
                int first = triangle[i][j] + next[j];
                int second = triangle[i][j+1] + next[j+1];

                curr[j] = min(first,second);
            }
            next = curr;
        }

        return triangle[0][0] + curr[0];
        
    }
};