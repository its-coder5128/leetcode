class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> m;
        
        for(auto it:nums)
        {
            m[it]++;
        }
        
        int ans = 0;
        
        for(auto it:m)
        {
            if(it.second == 2)
            {
                ans ^= it.first;
            }
        }
        
        return ans;
    }
};