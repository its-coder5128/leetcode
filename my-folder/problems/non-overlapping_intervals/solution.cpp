class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[1] < b[1])
            return true;
        if(a[1] == b[1])
            return a[1] > b[1];

        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);

        int e = intervals[0][1];
        int cnt = 0;
        int n = intervals.size();
        
        for(int i = 1;i<n;i++)
        {
            if(e > intervals[i][0])
                cnt++;
            else
                e = intervals[i][1];
            
        }

        return cnt;


    }
};