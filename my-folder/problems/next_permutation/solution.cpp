class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int miniIND = n-1;
        int mini = INT_MAX;
        int index = 0;

        for(int i = n-1;i > 0;i--)
        {
            if(nums[i] > nums[i-1])
            {
                index = i;
                break;
            }
        }
        if(index)
        {for(int i = index;i<n;i++)
        {
            if(nums[i] > nums[index-1] && mini > nums[i])
            {
                miniIND = i;
                mini = nums[i];
            }
        }
        swap(nums[index-1],nums[miniIND]);}
        sort(nums.begin() + index,nums.end());

        
    }
};