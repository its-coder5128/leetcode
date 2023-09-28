class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int e=0;
        int o=0;

        while(o<nums.size())
        {
            if(nums[o] & 1)
            {
                o++;
            }
            else
            {
                swap(nums[e++],nums[o++]);
            }
        }

        return nums;
        
    }
};