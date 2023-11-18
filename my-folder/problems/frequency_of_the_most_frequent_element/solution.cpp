class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int i = 0;
        int j = 0;
        int maxi = 1;

        while(j<nums.size()-1)
        {
            long x = ((long)(nums[j+1] - nums[j])*(long)(j-i+1));
            if((long)k >= x)
            {
                k = k - (nums[j+1] - nums[j])*(j-i+1);
                j++;
                maxi = max(maxi,j - i + 1);
            }
            else
            {
                k = k + nums[j] - nums[i];
                i++;
                j = max(i,j);
            }
        }

        return maxi;
        
    }
};