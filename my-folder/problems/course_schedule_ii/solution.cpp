class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {

        unordered_map<int,list<int>> m;
        vector<int> inDegree(n,0);

        for(int i = 0;i<pre.size();i++)
        {
            m[pre[i][1]].push_back(pre[i][0]);
            inDegree[pre[i][0]]++;
        }
        queue<int> q;
        for(int i = 0;i<n;i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(auto i : m[front])
            {
                inDegree[i]--;
                if(inDegree[i] == 0)
                    q.push(i);
            }
        }

        if(ans.size() == n)
            return ans;
        return {};
    }
};