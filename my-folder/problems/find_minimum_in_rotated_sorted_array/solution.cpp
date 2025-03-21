class Solution {
public:
    int findMin(vector<int>& nums) {

        int s = 0;
        int e = nums.size()-1;

        while(s<=e)
        {
            int m = s + (e-s)/2;

            if(nums[m] >= nums[0])
                s = m + 1;
            else
                e = m - 1;
        }
        return nums[s%nums.size()];
        
    }
};