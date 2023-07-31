class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,list<int>> m;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].push_back(i);
        }

        vector<int> temp;
        for(int i=0;i<nums.size();i++)
        {
            int first = nums[i];

            int second = target - nums[i];

            if( m.count(second) != 0 )
            {
                int index=m[second].back();
                if(index != i || (index == i && m[second].size()>1) )
                {
                    temp.push_back(i);
                    temp.push_back(index);
                    return temp;
                }
            }
        }

        return temp;

        
    }
};