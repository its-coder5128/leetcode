class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> m;
        m[0] = 1;

        int ans = 0;
        int n = nums.size();
        int sum = 0;

        for(int i = 0;i<n;i++)
        {
            sum += nums[i];

            int rem = sum - k;

            if(m.find(rem) != m.end())
                ans+=m[rem];
            
            m[sum]++;

        }

        return ans;
        
    }
};