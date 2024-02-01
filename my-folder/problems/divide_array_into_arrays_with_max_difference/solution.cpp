class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        vector<vector<int>> arr(nums.size()/3,vector<int>(3));

        int i = 0;
        int j = 0;
        while(i<nums.size())
        {
            if(nums[i+2] - nums[i] <= k)
                arr[j++] = {nums[i],nums[i+1],nums[i+2]};
            else
                return {};
            i = i+3;
        }

        return arr;
        
    }
};