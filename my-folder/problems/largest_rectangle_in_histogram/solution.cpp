class Solution {
public:
    vector<int> nextSmall(vector<int> heights,int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--)
        {
            while(s.top()!=-1 && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            
            ans[i]=s.top();

            s.push(i);


        }
        return ans;
    }
    vector<int> prevSmall(vector<int> heights,int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0;i<n;i++)
        {
            while(s.top()!=-1 && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            
            ans[i]=s.top();

            s.push(i);


        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();

        vector<int> next(n);
        next=nextSmall(heights,n);
        
        vector<int> prev(n);
        prev=prevSmall(heights,n);

        int area=-1;
       

        for(int i=0;i<n;i++)
        {
            int length=heights[i];

            if(next[i]==-1)
            {
                next[i]=n;
            }
            int breadth=next[i]-prev[i]-1;

            int newArea=length*breadth;

            area=max(area,newArea);

        }

        return area;
    }
};