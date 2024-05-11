class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = -1;
        int cnt = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++)
        {
            if(!nums[i])
                cnt = 0;
            else
                cnt++;
            
            maxi = max(maxi,cnt);
        }

        return maxi;
    }
};