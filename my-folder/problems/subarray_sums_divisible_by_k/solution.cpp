class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        vector<int> temp(k,0);
        temp[0] = 1;

        for(int i= 0;i<n;i++)
        {
            sum += nums[i];

            int mod = sum%k;

            if(mod < 0)
                mod = (mod + k)%k;

            if(temp[mod] != 0)
            {
                ans += temp[mod];
                temp[mod]++;
            }
            else{
                temp[mod] = 1;
            }
        }

        return ans;

    }
};