class Solution {
public:
    int check(vector<int>& nums, int divisor)
    {
        int sum = 0;

        for(auto it:nums)
        {
            sum += ceil((double)it/(double)divisor);
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int s = 1;
        int e = *max_element(nums.begin(),nums.end());

        while(s<=e)
        {
            int m = s + (e-s)/2;

            int val = check(nums,m);

            // cout<<s<<" "<<m<<" "<<e<<" "<<val<<endl;

            if(val <= threshold)
            {
                e = m - 1;
            }
            else
                s = m + 1;
        }

        return s;
        
    }
};