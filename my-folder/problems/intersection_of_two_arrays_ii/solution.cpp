class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cnt(1001,0);

        for(auto it:nums1)
            cnt[it]++;
        
        vector<int> ans;

        for(auto it:nums2)
        {
            if(cnt[it] > 0)
            {
                ans.push_back(it);
                cnt[it]--;
            }
        }

        return ans;
    }
};