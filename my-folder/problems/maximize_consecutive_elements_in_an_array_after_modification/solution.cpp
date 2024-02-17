class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int> m;
        
        int ans = 0;
        
        for(auto num:nums)
        {
            int same = max(m[num],1 + m[num-1]);
            int inc = max(m[num+1],1 + m[num]);
            
            m[num] = same;
            m[num+1] = inc;
            
            ans = max({ans,same,inc});
        }
        
        return ans;
        
    }
};