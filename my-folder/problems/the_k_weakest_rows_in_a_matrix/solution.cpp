class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        priority_queue<pair<int,int>> q;

        for(int i=0;i<mat.size();i++)
        {
            int sum = 0;
            for(int j=0;j<mat[0].size();j++)
            {
                sum += mat[i][j];
            }

            if(q.size()<k)
            {
                q.push({sum,i});
            }
            else if(q.top().first>sum)
            {
                q.pop();
                q.push({sum,i});
            }
        }

        vector<int> ans;

        while(!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};