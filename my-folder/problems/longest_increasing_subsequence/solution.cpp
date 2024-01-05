class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> lis;
        lis.push_back(nums[0]);

        for(int num:nums)
        {
            int index = lower_bound(lis.begin(),lis.end(),num) - lis.begin();

            if(index == lis.size())
                lis.push_back(num);
            else
                lis[index] = num;
        }

        return lis.size();
        
    }
};