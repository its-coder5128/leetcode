class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        set<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i] > 0)
                break;
            int j=i+1;
            int k=nums.size()-1;

            while(j<k)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    ans.insert({nums[i],nums[j++],nums[k--]});
                }
                else if(nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else
                    j++;
            }
        }

        for(auto i:ans)
            result.push_back(i);

        return result;
        
    }
};