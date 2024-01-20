class Solution {
public:
    int countBits(int num)
    {
        int ans = 0;
        
        for(int i = 0;i<32;i++)
        {
            int temp = 1<<i;
            
            if(temp & num)
                ans++;
        }
        
        return ans;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    int x = countBits(nums[j]);
                    int y = countBits(nums[j+1]);
                    
                    if(x == y)
                        swap(nums[j],nums[j+1]);
                    else
                        return false;
                }
            }
        }
        
        return true;
        
    }
};