class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int maxProd = -1;
        for(int i = 1;i<nums.size();i++)
        {   
            maxProd = max(maxProd,(maxi-1)*(nums[i]-1));
            maxi = max(nums[i],maxi);
        }
        return maxProd;
    }
};