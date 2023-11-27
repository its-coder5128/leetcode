class Solution {
public:
    int mod = 1e9 + 7;
    int solve(vector<vector<int>> &m,int node,int left,vector<vector<int>> &dp)
    {
        if(left == 0)
            return 1;
        if(left == 1)
            return m[node].size();
        if(dp[node][left] != -1)
            return dp[node][left];
        
        int cnt = 0;

        for(auto i:m[node])
        {
            cnt = ((long long)cnt + (long long)solve(m,i,left-1,dp))%(mod);
        }

        return dp[node][left] = cnt;
    }
    int knightDialer(int n) {

        vector<vector<int>> m(10);
        vector<vector<int>> dp(10,vector<int>(n,-1));
        m[0] = {4,6};
        m[1] = {6,8};
        m[2] = {7,9};
        m[3] = {4,8};
        m[4] = {3,9,0};
        m[5] = {};
        m[6] = {1,7,0};
        m[7] = {2,6};
        m[8] = {1,3};
        m[9] = {2,4};

        int ans = 0;

        for(int i = 0;i<10;i++)
        {
            ans = (ans+ solve(m,i,n-1,dp))%mod;
        }

        return ans;
        
    }
};