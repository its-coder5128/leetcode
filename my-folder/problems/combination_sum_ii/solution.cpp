class Solution {
public:
    void solve(vector<int>& cand, int target,vector<vector<int>>& ans,vector<int>& temp,int index)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        else if(target < 0 || index == cand.size() || cand[index] > target)
            return;

        for(int i = index;i<cand.size();i++)
        {
            if(i>index && cand[i] == cand[i-1]) continue;
            if(cand[i] > target)    break;
            temp.push_back(cand[i]);
            solve(cand,target-cand[i],ans,temp,i+1);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(),candidates.end());

        solve(candidates,target,ans,temp,0);

        return ans;
    }
};