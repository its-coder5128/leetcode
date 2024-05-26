class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int ans = 0;
        
        for(auto it1:nums1)
        {
            for(auto it2:nums2)
            {
                if(it1%(it2*k) == 0)
                    ans++;
            }
        }
        
        return ans;
    }
};