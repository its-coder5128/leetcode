class Solution {
public:
    vector<int> nextSmall(vector<int> arr,int n)
    {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for(int i=n-1;i>=0;i--)
        {
            while(s.top() != -1 && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }
    vector<int> prevSmall(vector<int> arr,int n)
    {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for(int i=0;i<n;i++)
        {
            while(s.top() != -1 && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }
    int maxArea(vector<int> arr,int n)
    {
        vector<int> next(n);
        next = nextSmall(arr,n);
        
        vector<int> prev(n);
        prev = prevSmall(arr,n);

        int mArea = INT_MIN;

        for(int i=0;i<n;i++)
        {
            int l = arr[i];

            if(next[i] == -1)
                next[i] = n;
            
            int b = next[i] - prev[i] - 1;

            mArea = max(mArea,l*b);
        }

        return mArea;
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