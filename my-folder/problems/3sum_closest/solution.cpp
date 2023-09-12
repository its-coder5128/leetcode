class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int mini = INT_MAX;
        sort(nums.begin(),nums.end());

        int ans = 0;


        for(int i = 0 ;i<nums.size();i++ )
        {
            int j = i+1;
            int k = nums.size()-1;


            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                int dist = abs(sum - target);

                if( dist < mini)
                {
                    mini = dist;
                    ans = sum;
                }

                if(sum > target)
                {
                    k--;
                }
                else if(sum < target)
                {
                    j++;
                }
                else
                    return sum;
            }
        }

        return ans;
        
    }
};