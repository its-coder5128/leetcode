class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;

        int cnt1 = 0;
        int cnt2 = 0;
        int cand1=0,cand2=0;

        for(int i=0;i<nums.size();i++)
        {
            if(cand1 == nums[i])
                cnt1++;
            else if(cand2 == nums[i])
                cnt2++;
            else if(cnt1 == 0)
            {
                cand1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0)
            {
                cand2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == cand1)
                cnt1++;
            else if(nums[i] == cand2)
                cnt2++;
        }
        if(cnt1 > nums.size()/3)
            ans.push_back(cand1);
        if(cnt2 > nums.size()/3)
            ans.push_back(cand2);
            

        return ans;
    }
};