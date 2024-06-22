class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int cnt = 0;
        int n = nums.size();
        
        for(int i = 0;i<=n-3;i++)
        {
            if(nums[i] == 0)
            {
                cnt++;
                for(int j = i;j<i+3;j++)
                {
                    nums[j] = !nums[j];
                }
            }
        }
        
        for(int i = n-3;i<n;i++)
        {
            if(nums[i] == 0)
                return -1;
        }
        
        return cnt;
        
    }
};