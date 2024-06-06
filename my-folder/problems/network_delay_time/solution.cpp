class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n+1];

        for(auto it:times)
        {
            int u = it[0];
            int v = it[1];
            int cost = it[2];

            adj[u].push_back({v,cost});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

        q.push({0,k});

        vector<int> dist(n+1,1e9);
        dist[k] = 0;

        while(!q.empty())
        {
            int node = q.top().second;
            int cost = q.top().first;
            q.pop();
            
            for(auto it:adj[node])
            {
                if(dist[it.first] > cost + it.second)
                {
                    dist[it.first] = cost + it.second;
                    q.push({cost + it.second,it.first});
                }

            }
        }
        int ans = *max_element(dist.begin()+1,dist.end());
        return  ans == 1e9 ? -1 : ans;


    }
};