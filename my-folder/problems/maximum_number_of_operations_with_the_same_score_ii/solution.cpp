class Solution {
public:
    int solve(vector<int>& nums,int score,int i,int j,vector<vector<int>>& dp)
    {
        if(i>=j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int f = 0,s = 0,t = 0;
        if((nums[i]+nums[i+1]) == score)
            f = 1 + solve(nums,score,i+2,j,dp);
        if((nums[i] + nums[j]) == score)
            s = 1 + solve(nums,score,i+1,j-1,dp);
        if((nums[j] + nums[j-1]) == score)
            t = 1 + solve(nums,score,i,j-2,dp);
        
        return dp[i][j]=max(s,max(f,t));
            
    }
    int maxOperations(vector<int>& nums) {
        
        int s1 = nums[0] + nums[1];
        int s2 = nums[0] + nums[nums.size() - 1];
        int s3 = nums[nums.size() - 1] + nums[nums.size() - 2];
        
        int maxi = 0;
        vector<vector<int>> dp1(nums.size()+1,vector<int>(nums.size() + 1,-1));
        vector<vector<int>> dp2(nums.size()+1,vector<int>(nums.size() + 1,-1));
        vector<vector<int>> dp3(nums.size()+1,vector<int>(nums.size() + 1,-1));
        maxi = max(maxi , solve(nums,s1,2,nums.size()-1,dp1));
        maxi = max(maxi , solve(nums,s2,1,nums.size()-2,dp2));
        maxi = max(maxi , solve(nums,s3,0,nums.size()-3,dp3));
        
    
        return maxi + 1;
        
    }
};