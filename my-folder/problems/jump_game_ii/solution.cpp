class Solution {
public:
    int solve(vector<int> &nums,int n,int index,vector<int> &dp)
    {
        if(index == n - 1)
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        int ans = 1e9+7;

        for(int i = 1;i<=nums[index] && index+i < n;i++)
        {
            ans = min(ans,1 + solve(nums,n,index+i,dp));
        }

        return dp[index] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        cout<<n-1<<endl;
        
        int steps = 0;
        int maxi = 0;
        int i = 0;
        while(i<n-1)
        {
            if(maxi >= n-1) return steps;

            int maxi1 = -1;

            for(int j = i;j<=maxi;j++)
            {
                maxi1 = max(maxi1,j+nums[j]);
            }
            if(maxi1 > maxi)
            {
                i = maxi;
                maxi = maxi1;
                steps++;
            }
        }
        return steps;
        
    }
};