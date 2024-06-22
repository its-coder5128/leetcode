class Solution {
public:
    int solve(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        stack<int> stk;
        for(int i = 0;i<=n;i++)
        {
            while(!stk.empty() && (i == n || heights[stk.top()] >= heights[i]))
            {
                int h = heights[stk.top()];
                stk.pop();
                int r = i;
                int l = -1;
                if(!stk.empty())
                    l = stk.top();
                int w = r-l-1;
                maxi = max(maxi,w*h);
            }
            stk.push(i);
        }

        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();

        vector<int> arr(m,0);

        int maxi = 0;

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(matrix[i][j] == '1')
                    arr[j] += 1;
                else
                    arr[j] = 0;
            }

            maxi = max(maxi,solve(arr));
        }

        return maxi;

    }
};