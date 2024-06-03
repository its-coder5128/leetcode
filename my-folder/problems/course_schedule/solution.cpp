class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<int> adj[n];

        for(int i = 0;i<arr.size();i++)
        {
            adj[arr[i][1]].push_back(arr[i][0]);
        }

        queue<int> q;
        vector<int> indegree(n,0);
        vector<int> topo;

        for(int i = 0;i<n;i++)
        {
            for(auto it:adj[i])
                indegree[it]++;
        }
        for(int i = 0;i<n;i++)
            if(indegree[i] == 0)
                q.push(i);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo.size() == n;
    }
};