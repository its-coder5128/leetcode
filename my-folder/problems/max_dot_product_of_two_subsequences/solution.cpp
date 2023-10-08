class Solution {
public:
    int mini = (int)-1e9;

    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp)
    {
        if( i == nums1.size() || j == nums2.size())
            return mini;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int maxi = max( nums1[i]*nums2[j] + max(solve(i+1,j+1,nums1,nums2,dp),0) 
                    ,max( solve(i+1,j,nums1,nums2,dp)
                        ,max(solve(i,j+1,nums1,nums2,dp)
                            ,solve(i+1,j+1,nums1,nums2,dp))) );

        return dp[i][j] = maxi;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        //vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,mini));

        vector<int> curr(nums2.size()+1,mini);
        vector<int> next(nums2.size()+1,mini);

        for(int i=nums1.size()-1;i>=0;i--)
        {
            for(int j=nums2.size()-1;j>=0;j--)
            {
                int maxi = max( nums1[i]*nums2[j] + max(next[j+1],0) 
                    ,max( next[j]
                        ,max(curr[j+1]
                            ,next[j+1])) );

                curr[j] = maxi;
            }
            next = curr;
        }

        return curr[0];


        //return solve(0,0,nums1,nums2,dp);
        
    }
};