class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto it:flights)
        {
            int u = it[0];
            int v = it[1];
            int cost = it[2];

            adj[u].push_back({v,cost});
        }

        queue<vector<int>> q;
        q.push({0,0,src});
        vector<int> dist(n,1e9);
        dist[src] = 0;

        while(!q.empty())
        {
            int node = q.front()[2];
            int cost = q.front()[1];
            int stops = q.front()[0];
            q.pop();
            
            for(auto it:adj[node])
            {
                if( stops <= k && dist[it.first] > cost + it.second)
                {
                    dist[it.first] = cost + it.second;
                    q.push({stops + 1,cost + it.second,it.first});
                }

            }
        }
        if(dist[dst] != 1e9)
            return dist[dst];
        return -1;
    }
};