class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n=nums.size();

        int mini = INT_MAX;

        int sum = 0;
        int i=0,j=0;

        while(i<n && j<=i)
        {
           sum = sum + nums[i];

            if( sum >= target)
            {
                mini = min( mini , i - j + 1);
                while(sum >= target)
                {
                    mini = min( mini , i - j + 1);
                    sum = sum - nums[j];
                    j++;
                }

            } 
            i++;
        }
        

        if(mini != INT_MAX)
            return mini;
        else
            return 0;    
        
    }
};