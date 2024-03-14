class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int,int> m;
        m[0] = 1;

        int sum = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
            ans += m[sum - goal];
            m[sum]++;
        }

        return ans;
        
    }
};