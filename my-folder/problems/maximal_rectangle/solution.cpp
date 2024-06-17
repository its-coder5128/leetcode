class Solution {
public:
   
    int maxArea(vector<int> arr,int n)
    {
        stack<int> s;
        int maxArea = 0;

        for(int i= 0;i<=n;i++)
        {
            while(!s.empty() && (i == n || arr[s.top()] >= arr[i]))
            {
                int h = arr[s.top()];
                s.pop();
                int r = i;

                int l = -1;
                if(!s.empty())
                    l = s.top();
                
                maxArea = max(maxArea,h*(r-l-1));
            }
            s.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<int> mat(matrix[0].size(),0);
        int maxi=-1;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == '1')
                    mat[j]++;
                else
                    mat[j] = 0;
            }

            maxi = max(maxi,maxArea(mat,matrix[0].size()));

        }
        return maxi;
    }
};