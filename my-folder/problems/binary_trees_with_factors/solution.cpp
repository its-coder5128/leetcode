class Solution {
public:
    const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {

        sort(arr.begin(),arr.end());
        int sum = 0;
        unordered_map<int,int> dp;
        dp[1] = 0;

        for(int i =0;i<arr.size();i++)
        {
            int x = sqrt(arr[i]);
            for(int j=0;arr[j]<=x;j++)
            {
                if(arr[i] % arr[j] == 0 && dp[arr[i]/arr[j]])
                {
                    long long left = dp[arr[j]]%mod;
                    long long right = dp[arr[i]/arr[j]]%mod;

                    if(arr[j] != arr[i]/arr[j])
                        dp[arr[i]] = ( dp[arr[i]] + 2*left*right)%mod;
                    else
                        dp[arr[i]] = ( dp[arr[i]] + left*right)%mod;
                }
            }
            dp[arr[i]]++;
            sum = (sum + dp[arr[i]]) % mod;
        }

        return sum;
    }
};