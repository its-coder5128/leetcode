class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        bool flag = true;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        for(int i = 0;i<nums.size();i+=3)
        {
            if(!(i+1 < n && nums[i] == nums[i + 1] && i+2<n && nums[i] == nums[i+2]))
            {
                flag = false;
                ans = nums[i];
                break;
            }
        }
        
        return ans;
    }
};