class Solution {
public:
    int maxProductDifference(vector<int>& nums) {

        int m1 = nums[0],M1 = nums[0];
        int m2 = INT_MAX,M2 = INT_MIN;

        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] > M1){
                M2 = M1;
                M1 = nums[i];
            }
            else if(nums[i] > M2)
                M2 = nums[i];

            if(nums[i] < m1){
                m2 = m1;
                m1 = nums[i];
            }
            else if(nums[i] < m2)
                m2 = nums[i];
            
        }

        return M1*M2 - m1*m2;
        
    }
};