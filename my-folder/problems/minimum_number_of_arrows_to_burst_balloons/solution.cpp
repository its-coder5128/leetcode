class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());

        vector<int> overLap = points[0];
        int arrow = 1;

        for(int i = 1;i<points.size();i++)
        {
            if(points[i][0] <= overLap[1])
            {
                overLap[0] = points[i][0];
                overLap[1] = min(points[i][1],overLap[1]);
            }
            else{
                arrow++;
                overLap[0] = points[i][0];
                overLap[1] = points[i][1];
            }
        }

        return arrow;
    }
};