class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int,int> m;

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            if(m[nums[i]]==1)
            {
                return nums[i];
            }
        }

        return -1;
        
    }
};