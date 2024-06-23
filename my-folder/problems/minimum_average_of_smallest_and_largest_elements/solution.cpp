class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double mini = INT_MAX;
        
        sort(nums.begin(),nums.end());
        
        int i = 0;
        int j = nums.size()-1;
        
        while(i<j)
        {
            double avg = (nums[i]+nums[j])/(double)2;
            if(mini > avg)
                    mini = avg;
            i++;
            j--;
        }
        
        return mini;
    }
};