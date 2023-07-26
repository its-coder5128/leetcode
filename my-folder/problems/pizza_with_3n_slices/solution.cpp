class Solution {
public:
    int solve(vector<int>& slices,int index,int n,int count,vector<vector<int>>& dp)
    {
        if(index >= n || (count == slices.size()/3))
            return 0;

        if( dp[index][count] != -1)
            return  dp[index][count];

        int include = slices[index] + solve(slices , index + 2,n,count+1,dp);
        int exclude = 0 + solve(slices,index+1,n,count,dp);

        dp[index][count] = max(include,exclude);
        return dp[index][count]; 
    }
    int solveTab(vector<int>& slices,int index,int n)
    {
        //vector<vector<int>> dp(n+2,vector<int>(slices.size()/3+1,0));
        vector<int> curr(slices.size()/3+1,0);
        vector<int> next(slices.size()/3+1,0);
        vector<int> next_next(slices.size()/3+1,0);

        for(int i=n-1;i>=index;i--)
        {
            for(int count=0;count<slices.size()/3;count++)
            {
                int include = slices[i] + next_next[count+1];
                int exclude = 0 + next[count];

                curr[count] = max(include,exclude);
            }
            next_next = next;
            next = curr;
        }

        return curr[0];
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        // vector<vector<int>> dp_1(n,vector<int>(n/3,-1));
        // vector<vector<int>> dp_2(n,vector<int>(n/3,-1));

        // int takingFirst = solve(slices,0,n-1,0,dp_1);

        // int notTakingFirst = solve(slices,1,n,0,dp_2);

        int takingFirst = solveTab(slices,0,n-1);

        int notTakingFirst = solveTab(slices,1,n);
        
        return max(takingFirst,notTakingFirst);
    }
};