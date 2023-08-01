class Solution {
public:
    int solve(vector<int>& arr, int d,int index,int ele,unordered_map<int,int> dp[])
    {
        if(index == arr.size())
            return 0;

        if(dp[index].count(ele))
            return dp[index][ele];
        
        int exclude = 0 + solve(arr,d,index+1,ele,dp);

        int include = 0;

        if(ele == INT_MIN)
        {
            include = 1 + solve(arr,d,index+1,arr[index],dp);
        }
        else if( arr[index] - ele == d)
            include = 1 + solve(arr,d,index+1,arr[index],dp);

        dp[index][ele] = max(include,exclude);
        
        return dp[index][ele];
    } 
    int longestSubsequence(vector<int>& arr, int d) {

        unordered_map<int,int> dp;
        int ans=1;
        for(int i=0;i<arr.size();i++)
        {
            int prev = arr[i] - d;
            int x=0;
            if(dp.count(prev))
            {
                x = dp[prev] + 1;
                dp[arr[i]] = x;
            }
            else{
                x= 1;
                dp[arr[i]] = x;
            }
            ans = max(ans,x);
        }

        return ans;
    }
};