class Solution {
public:
    void solve(vector<int>& nums,int index,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(index == nums.size())
        {
            ans.push_back(temp);
            return;
        }


        


        temp.push_back(nums[index]);
        solve(nums,index+1,temp,ans);
        temp.pop_back();
            
        int i = index+1;
        while(i<nums.size() && nums[i] == nums[index])
            i++;
        index = i;
        solve(nums,index,temp,ans);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(),nums.end());

        solve(nums,0,temp,ans);

        return ans;
    }
};