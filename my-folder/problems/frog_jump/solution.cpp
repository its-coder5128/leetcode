class Solution {
public:
    bool solve(vector<int>& stones,int index,int k,int n,unordered_map<int,int> dp[])
    {
        if(index == n - 1)
            return true;
        if(dp[index].count(k)>0)
            return dp[index][k];
        
        bool canJump = false;
       
        for(int i = index+1;i<n;i++)
        {
            if(stones[i]-stones[index] == k-1)
                canJump = canJump || solve(stones,i,k-1,n,dp);
            if(stones[i]-stones[index] == k)
                canJump = canJump || solve(stones,i,k,n,dp);
            if(stones[i]-stones[index] == k+1)
                canJump = canJump || solve(stones,i,k+1,n,dp);
        }
        
        dp[index][k] = canJump;
        return canJump;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n == 1)
            return true;
        if(stones[1]-stones[0] != 1)
            return false;
        int index = 1;
        int k = 1;

        unordered_map<int,int> dp[n];
        return solve(stones,index,k,n,dp);
        
    }
};