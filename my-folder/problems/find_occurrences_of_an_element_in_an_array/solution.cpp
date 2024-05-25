class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int> m;
        
        int occur = 1;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == x)
            {
                m[occur++] = i;
            }
        }
        vector<int> ans;
        
        for(auto it:queries)
        {
            if(it >= occur)
            {
                ans.push_back(-1);
            }
            else if(m.find(it) != m.end())
            {
                ans.push_back(m[it]);
            }
            else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};