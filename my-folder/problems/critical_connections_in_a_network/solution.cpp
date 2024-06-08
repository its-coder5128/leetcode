class Solution {
public:
    void dfs(int node,int t,int parent,vector<int> adj[],vector<int> &time,vector<int> &low,vector<vector<int>> &ans)
    {
        time[node] = t;
        low[node] = t;

        for(auto it:adj[node])
        {
            if(it != parent)
            {
                if(time[it] == 0)
                {
                    dfs(it,t+1,node,adj,time,low,ans);
                    if(time[node] < low[it])
                    {
                        ans.push_back({node,it});
                    }
                }
                if(low[it] < low[node])
                    low[node] = low[it];
            }
        }

        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];

        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> time(n,0);
        vector<int> low(n,INT_MAX);
        vector<vector<int>> ans;

        dfs(0,1,-1,adj,time,low,ans);

        return ans;
    }
};