class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0;i<32;i++)
        {
            int cnt = 0;
            int x = 1<<i;
            for(int j = 0;j<nums.size();j++)
            {
                if(nums[j] & x)
                    cnt++;
            }
            
            if(k & x)
            {
                if(cnt%2 == 0)
                    ans++;
            }
            else
            {
                if(cnt%2 != 0)
                    ans++;
            }
        }
        
        return ans;
    }
};