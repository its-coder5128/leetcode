class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[0] <= b[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),cmp);
        
        int ans = INT_MIN;

        for(int i = 1;i < points.size(); i++ )
        {
            ans = max(ans,points[i][0] - points[i-1][0]);
        }

        return ans;


    }
};