class Solution {
public:
    void solve(vector<int>& cand,int tar,vector<vector<int>>& ans,vector<int>& temp,int index)
    {
        if(tar == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(tar<0 || index == cand.size())
            return;
        
        for(int i = index;i<cand.size();i++)
        {
            temp.push_back(cand[i]);
            solve(cand,tar-cand[i],ans,temp,i);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates,target,ans,temp,0);

        return ans;
    }
};