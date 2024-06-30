class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        int even = 0;
        int odd = 0;
        int eo = 0;
        int oe = 0;
        int turneo = 1;
        int turnoe = 1;
        for(int i= 0;i<n;i++)
        {
            if(nums[i] & 1)
            {
                odd++;
                if(turnoe == 1)
                {
                    oe++;
                    turnoe = !turnoe;
                }
                if(turneo == 0)
                {
                    eo++;
                    turneo = !turneo;

                }
            }
            else{
                even++;
                if(turneo == 1)
                {
                    eo++;
                    turneo = !turneo;
                }
                if(turnoe == 0)
                {
                    oe++;
                    turnoe = !turnoe;

                }
                
            }
        }
        
        return max({even,odd,eo,oe});
    }
};