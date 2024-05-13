class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        int pre = 1;
        int suff = 1;

        for(int i = 0;i<n;i++)
        {
            pre *= nums[i];
            suff *= nums[n-i-1];

            maxi = max(maxi,max(pre,suff));
            
            if(pre == 0)
                pre = 1;
            if(suff == 0)
                suff = 1; 
            
        }

        return maxi;
        
    }
};