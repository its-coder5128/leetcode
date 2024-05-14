class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int s = 0;
        int e = nums.size() - 1;

        int index = e+1;
        int mini = nums[e] + 1;

        while(s<=e)
        {
            int m = (s+e)/2;

            if(nums[m] >= target)
            {
                if(mini > nums[m])
                {
                    mini = nums[m];
                    index = m;
                }
                e = m - 1;
            }
            else
                s = m + 1;
        }

        return index;

        
    }
};