class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = nums[0];
        int cnt = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++)
        {
            if(cnt == 0)
            {
                cnt = 1;
                cand = nums[i];
            }
            else if(cand == nums[i])
                cnt++;
            else
                cnt--;
            
        }

        return cand;
        
    }
};