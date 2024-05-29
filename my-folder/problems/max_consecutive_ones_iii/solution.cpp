class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxi = 0;

        while(r < n)
        {
            if(nums[r] == 0)
                k--;
            
            if( k <= -1)
            {
                if(nums[l] == 0)
                    k++;
                l++;
            }
            if(k>=0)
                maxi = max(maxi,r-l+1);

            r++;
        }

        return maxi;
    }
};