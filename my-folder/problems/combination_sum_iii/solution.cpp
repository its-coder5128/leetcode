class Solution {
public:
    void solve(int n,int sum,vector<vector<int>> &ans,vector<int> &temp,int index)
    {
        if(sum == 0)
        {
            if(temp.size() == n)
                ans.push_back(temp);
            return;
        }
        if(sum<0 || n == temp.size())
            return;
        
        for(int i = index;i<=9;i++)
        {
            temp.push_back(i);
            solve(n,sum-i,ans,temp,i+1);
            temp.pop_back();
        }

        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(k,n,ans,temp,1);

        return ans;
    }
};