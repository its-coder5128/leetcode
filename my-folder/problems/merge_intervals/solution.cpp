class Solution {
public:
    static bool cmp(vector<int>& a1,vector<int>& a2)
    {
        if(a1[0] < a2[0])
            return true;
        
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),cmp);

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        int n = intervals.size();

        for(int i = 1;i < n;i++)
        {
            if(intervals[i][0] <= ans.back()[1])
                ans.back()[1] = max(intervals[i][1],ans.back()[1]);
            else
                ans.push_back(intervals[i]);
        }

        return ans;
        
    }
};