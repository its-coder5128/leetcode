class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> m;

        for(auto nums:matches)
        {
            m[nums[0]] = m[nums[0]];
            m[nums[1]]++;
        }

        vector<vector<int>> ans(2);

        for(auto i:m)
        {
            if(i.second == 0)
                ans[0].push_back(i.first);
            else if(i.second == 1)
                ans[1].push_back(i.first);
        }

        return ans;

        
    }
};