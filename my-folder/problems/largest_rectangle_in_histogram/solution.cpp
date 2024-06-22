class Solution {
public:
    vector<int> prevSmaller(vector<int>& heights,int n)
    {
        vector<int> ans(n,-1);
        stack<int> s;

        for(int i= 0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            
            if(!s.empty())
                ans[i] = s.top();
            
            s.push(i);
        }
        return ans;
    }
    vector<int> nextSmaller(vector<int>& heights,int n)
    {
        vector<int> ans(n,n);
        stack<int> s;

        for(int i= n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            
            if(!s.empty())
                ans[i] = s.top();
            
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // vector<int> left = prevSmaller(heights,n);
        // vector<int> right = nextSmaller(heights,n);

        int maxi = 0;

        // for(int i = 0;i<n;i++)
        // {
        //     int h = heights[i];
        //     int w = right[i] - left[i] - 1;
        //     maxi = max(maxi,h*w);
        // }
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
};