class Solution {
public:
    int solve(int n,int index,vector<int> &dp)
    {
        if(index == n)
            return 1;
        if(dp[index] != -1)
            return dp[index];
        
        int sum = 0;
        int mul = 1;

        for(int i=index;i<n;i++)
        {
            sum++;
            mul =max(mul, sum*solve(n,i+1,dp));
        }

        return dp[index] = mul;      
    }
    int integerBreak(int n) {

        if(n==2)    return 1;
        if(n==3)    return 2;
    
        vector<int> dp(n,-1);

        return solve(n,0,dp);

        int prod = 1;

        while(n>4)
        {
            prod *= 3;
            n = n - 3;
        }

        return prod*n;

        
    }
};