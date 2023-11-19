class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int cnt = 0;
        int ans = 0;
        int prev = nums[nums.size()-1];

        for(int i = nums.size()-1;i>=0;i--)
        {
            if(prev == nums[i])
                cnt++;
            else
            {
                ans += cnt;
                prev = nums[i];
                cnt++;
            }
        }

        return ans;
    }
};