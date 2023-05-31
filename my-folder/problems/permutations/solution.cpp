class Solution {

    private:
    void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>> &ans)
    {
        if(index>=nums.size())
        {
            ans.push_back(output);
            return;
        }

        int i=0;
        
        vector<int> temp;

        while(i<nums.size())
        {
            output.push_back(nums[i]);

            temp.assign(nums.begin(),nums.end());
            temp.erase(temp.begin()+i);
        
            solve(temp,output,index,ans);
            
            output.pop_back();
            i++;

            //nums.push_back(temp);

        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;

        solve(nums,output,index,ans);

        return ans;
    }
};