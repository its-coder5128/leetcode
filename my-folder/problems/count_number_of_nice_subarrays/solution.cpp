class Solution {
public:
    int solve(vector<int>& nums, int k,int odds,int n)
    {
        if(k<0)
            return 0;
        
        int l = 0;
        int r = 0;

        int cnt = 0;
        while(r<n)
        {
            if(nums[r]&1)
                odds++;
            
            while(odds>k)
            {
                if(nums[l]&1)
                    odds--;
                l++;
            }
            
                cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        return solve(nums,k,0,nums.size()) - solve(nums,k-1,0,nums.size());
        
    }
};