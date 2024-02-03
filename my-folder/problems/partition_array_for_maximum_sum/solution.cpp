class Solution {
public:
    int solve(vector<int>& arr,int k,int index,vector<int>& dp)
    {
        if(index >= arr.size())
            return 0;
        if(dp[index] != -1)
            return dp[index];
        
        int sum = 0;
        int maxi = INT_MIN;
        int n = arr.size();
        for(int i = index;i < min(index + k, n);i++)
        {
            maxi = max(maxi,arr[i]);

            sum = max(sum , maxi*(i-index+1) + solve(arr,k,i+1,dp));
        }

        return dp[index] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,-1);

        return solve(arr,k,0,dp);
        
    }
};