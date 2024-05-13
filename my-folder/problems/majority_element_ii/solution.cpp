class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0;
        int cand2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++)
        {
            if(cnt1 == 0 && cand2 != nums[i])
            {
                cand1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && cand1 != nums[i])
            {
                cand2 = nums[i];
                cnt2 = 1;
            }
            else if(cand1 == nums[i])
                cnt1++;
            else if(cand2 == nums[i])
                cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for(int i = 0;i<n;i++)
        {
            if(cand1 == nums[i]) cnt1++;
            else if(cand2 == nums[i]) cnt2++;
        }

        vector<int> ans;

        if(cnt1 > n/3) ans.push_back(cand1);
        if(cnt2 > n/3) ans.push_back(cand2);

        return ans;
    }
};