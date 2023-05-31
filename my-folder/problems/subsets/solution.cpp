class Solution {
private:
    void power_set(vector<int> num,vector<int> output,int index,vector<vector<int>> &ans )
    {
        if(index==num.size())
        {
            ans.push_back(output);
            return;
        }

        //exclude
        power_set(num,output,index+1,ans);

        //include
        int temp=num[index];
        output.push_back(temp);
        power_set(num,output,index+1,ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        power_set(nums,output,index,ans);

        return ans;

    }
};