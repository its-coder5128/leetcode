class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        unordered_map<int,int> m;
        int maxi = -1;

        for(int i = 0;i<nums.size();i++)
        {
            m[nums[i]]++;
            maxi = max(maxi,m[nums[i]]);
        }

        vector<vector<int>> ans(maxi);

        for(auto i:m)
        {
            int j = 0;
            while(i.second)
            {
                ans[j].push_back(i.first);
                i.second--;
                j++;
            }
        }

        return ans;
        
    }
};