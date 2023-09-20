class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int sum = 0;

        for(auto num : nums)
            sum += num;
        int target = sum - x;

        if(target == 0)
            return nums.size();
        
        int maxi = 0,curr_sum=0;

        int left = 0;

        for(int right = 0;right<nums.size();right++)
        {
            curr_sum += nums[right];

            while(curr_sum>target && left<=right)
            {
                curr_sum -= nums[left];
                left++;
            }

            if(curr_sum == target)
            {
                maxi = max(maxi,right-left+1);
            }
        }
        
        if(maxi)
            return nums.size() - maxi;
        return -1;
    }
};