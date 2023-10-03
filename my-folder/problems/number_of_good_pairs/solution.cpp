class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        unordered_map<int,int> m;

        int cnt = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i]) != m.end())
                cnt += m[nums[i]];
            
            m[nums[i]]++;
        }

        return cnt;
        
    }
};