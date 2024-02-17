class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int sum = nums[0] + nums[1];
        
        int i = 0;
        int cnt = 0;
        while(i < nums.size() && (nums[i] + nums[i+1]) == sum )
        {
            cnt++;
            i += 2;
        }
        
        return cnt;
    }
};