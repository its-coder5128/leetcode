class Solution {
public:
    vector<int> suffix(vector<int>& heights)
    {
        vector<int> suff(heights.size());

        stack<int> s;
        s.push(heights.size());

        for(int i=heights.size()-1;i>=0;i--)
        {
            while(s.top() != heights.size() && heights[i] <= heights[s.top()])
                s.pop();
            
            suff[i] = s.top();
            s.push(i);
        }

        return suff;
    }
    vector<int> prefix(vector<int>& heights)
    {
        vector<int> suff(heights.size());

        stack<int> s;
        s.push(-1);

        for(int i=0;i<heights.size();i++)
        {
            while(s.top() != -1 && heights[i] <= heights[s.top()])
                s.pop();
            
            suff[i] = s.top();
            s.push(i);
        }

        return suff;
    }
    int largestRectangleArea(vector<int>& heights) {

        vector<int> pref = prefix(heights);
        vector<int> suff = suffix(heights) ;

        int maxi = -1;

        for(int i = 0;i<heights.size();i++)
        {
            maxi = max(maxi, (suff[i] - pref[i] - 1)*heights[i]);
        }

        return maxi;


        
    }
};