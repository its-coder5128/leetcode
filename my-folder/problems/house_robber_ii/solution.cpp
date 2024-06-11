class Solution {
public:
    int solve(vector<int>& nums,int n,int base)
    {
        int p1 = nums[base];
        int p2 = 0;

        for(int i = base + 1;i<n;i++)
        {
            int curr = max(0 + p1,nums[i] + p2);
            p2 = p1;
            p1 = curr;
        }

        return p1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return *max_element(nums.begin(),nums.end());
        return max(solve(nums,n,1),solve(nums,n-1,0));
    }
};