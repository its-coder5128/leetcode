class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum & 1)
            return false;
        sum /= 2;
        int n = nums.size();

        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        vector<int> prev(sum+1,0);
        vector<int> curr(sum+1,0);
        curr[0] = true;
        prev[0] = true;

        if(nums[0] <= sum)
            prev[nums[0]] = true;
        
        for(int index = 1;index<n;index++)
        {
            for(int k = 1;k<=sum;k++)
            {
                int notTake = prev[k];
                int take = false;
                if(k - nums[index] >= 0)
                    take = prev[k - nums[index]];

                curr[k] = take | notTake;
            }
            prev = curr;
        }

        return prev[sum];
    }
};