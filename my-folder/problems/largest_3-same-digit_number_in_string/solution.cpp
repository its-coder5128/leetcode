class Solution {
public:
    string largestGoodInteger(string nums) {

        int maxi = -1;

        for(int i = 0;i<nums.size()-2;i++)
        {
            if(nums[i] == nums[i+1] && nums[i] == nums[i+2])
            {  
                maxi = max(maxi, nums[i] - '0');
            }
        }

        if(maxi == -1)
            return "";
        else
        {
            string ans = "";
            ans += maxi+'0';
            ans += maxi+'0';
            ans += maxi+'0';
            return ans;
        }

        
    }
};