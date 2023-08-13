class Solution {
public:
    bool solve(vector<int> &nums,int index,vector<int> &dp)
    {
        if(index == nums.size())
            return true;
        if(index + 1 == nums.size())
            return false;
        if(dp[index] != -1)
            return dp[index];
        
        bool two = false;
        bool three = false;

        if(index + 1 < nums.size() && nums[index] != nums[index+1])
        {
            if(index + 2 >= nums.size())
                return false;
            else if( (nums[index + 1] - nums[index] == 1 ) && (nums[index+2]-nums[index+1] == 1) )
                three = solve(nums,index+3,dp);    
            else
                return false;       
        }
        else if(index + 1 < nums.size() && nums[index] == nums[index+1])
        {
            two = solve(nums,index+2,dp);

            if(index + 2 <nums.size() && nums[index] == nums[index+2])
                three = solve(nums,index+3,dp);          
        }

        dp[index] = two || three;
        return two || three;
    }
    bool validPartition(vector<int>& nums) {

        vector<int> dp(nums.size(),-1);
        
        return solve(nums,0,dp);
        
    }
};