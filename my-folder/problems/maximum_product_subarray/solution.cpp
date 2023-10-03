class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int pre = 1;
        int suff = 1;

        int maxi = INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            pre *= nums[i];
            suff *= nums[nums.size()-i-1];

            maxi = max(maxi,max(pre,suff));

            if(pre == 0)
                pre = 1;
            if(suff == 0)
                suff = 1;
        }
        
        return maxi;
    }
};