class Solution {
public:
    int splits(vector<int>& nums, int k)
    {
        int sum = 0;
        int ans = 1;

        int n = nums.size();

        for(int i = 0;i<n;i++)
        {
            if(sum + nums[i] <= k)
                sum += nums[i];
            else
            {
                ans++;
                sum = nums[i];
            }
        }

        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int s = INT_MIN;
        int e = 0;

        for(auto it:nums)
        {
            s = max(s,it);
            e += it;
        }

        while(s <= e)
        {
            int m = s + (e-s)/2;

            int val = splits(nums,m);

            if(val > k)
                s = m + 1;
            else
                e = m - 1;
        }

        return s;
    }
};