class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        int flag = nums[n-1];
        int cnt = 0;
        
        for(int i = n - 1;i>0;i--)
        {
            if(flag != nums[i-1])
            {
                cnt++;
                flag = nums[i-1];
            }
        }
        
        if(flag == 0)
            cnt++;
        
        return cnt;
        
    }
};