class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
        int n = nums.size();
        int r = 0;
        int l = 0;
        int cnt = 0;
        vector<int> m(n+1,0);
        int dist = 0;

        while(r<n)
        {
            m[nums[r]]++;
            if(m[nums[r]] == 1)
                dist++;

            while(dist > k)
            {
                m[nums[l]]--;
                if(m[nums[l]] == 0)
                    dist--;
                l++;
            }
            cnt += r - l + 1;
            r++;
        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};