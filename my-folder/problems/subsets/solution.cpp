class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int x = (1<<(n)) - 1;
        int cnt = 0;

        vector<vector<int>> ans;

        // cout<<x;
        while(cnt <= x)
        {
            vector<int> temp;

            for(int i = 0;(1<<i) <= cnt ;i++)
            {
                if(cnt & (1<<i))
                    temp.push_back(nums[i]);
            }
            cnt++;
            ans.push_back(temp);
        }

        return ans;
        
    }
};