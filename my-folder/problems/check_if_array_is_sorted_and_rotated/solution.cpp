class Solution {
public:
    bool check(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        for(int i = 1;i<n;i++)
        {
            if(nums[i-1] > nums[i])
            {
                index = i;
                break;
            }
        }

        for(int i = 1;i<n;i++)
        {
            if(nums[(index + i - 1)%n] > nums[(index + i)%n])
                return false; 
        }

        return true;
    }
};