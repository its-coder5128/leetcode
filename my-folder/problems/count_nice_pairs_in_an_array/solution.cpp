class Solution {
public:
    int rev(int x)
    {
        int y = 0;

        while(x)
        {
            y = y*10 + x%10;
            x = x/10;
        }

        return y;
    }
    int countNicePairs(vector<int>& nums) {

        int cnt = 0;
        int mod = 1e9 + 7;

        unordered_map<int,int> m;

        for(auto num:nums)
        {
            int x = num - rev(num);
            cnt = (cnt + m[x])%mod;
            m[x]++;
        }
        return cnt;
    }
};