class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,0);

        for(int i = 0;i<n;i++)
            hash[i] = i;
        
        for(int i = 0;i<n;i++)
        {
            for(int prev = 0;prev<i;prev++)
            {
                if(dp[i] < dp[prev] + 1 && nums[i]%nums[prev] == 0)
                {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;    
                }
            }
        }

        int maxi = 0;
        int index = 0;

        for(int i = 0;i<n;i++)
        {
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                index = i;
            }
        }
        vector<int> ans;
        while(hash[index] != index)
        {
            ans.emplace_back(nums[index]);
            index = hash[index];
        }
        ans.emplace_back(nums[index]);

        return ans;

    }
};