class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int maxi = INT_MIN;

        int i=0;

        while(i<nums.size())
        {
            if(sum<0)
                sum = 0;

            sum += nums[i++];

            maxi = max(sum,maxi);
        }

        return maxi;

        
    }
};