class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        int rightSum = 0;
        int leftSum = 0;
        int n = nums.size();

        for(auto num : nums)
            rightSum += num;
        
        vector<int> ans(n);

        for(int i = 0;i<n;i++)
        {
            int temp = abs(rightSum - (n - i)*nums[i]) + abs(leftSum - i*nums[i]);
            ans[i]=temp;
            rightSum -= nums[i]; 
            leftSum += nums[i]; 
        }

        return ans;
        
    }
};