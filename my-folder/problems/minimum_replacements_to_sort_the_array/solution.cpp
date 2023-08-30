class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

        int curr_largest = nums[nums.size() - 1];
        long long ans = 0;

        for(int i = nums.size()-1;i>=0;i--)
        {
            if(nums[i] <= curr_largest)
            {
                curr_largest = nums[i];
                continue;
            }

            int no_of_ele = 0;
            if(nums[i] % curr_largest) 
                no_of_ele = ceil(nums[i] / curr_largest) +1;
            else
                no_of_ele = ceil(nums[i] / curr_largest);

            curr_largest = nums[i] / no_of_ele;
            ans += no_of_ele - 1;

        }

        return ans;
    }
};