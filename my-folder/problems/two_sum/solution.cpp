class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int> m;

        for(int i = 0;i<n;i++)
        {
            int moreNeeded = target - nums[i];

            if(m.find(moreNeeded) != m.end())
                return {m[moreNeeded],i};
                
            m[nums[i]] = i;
        }

        return {-1,-1};
    }
};