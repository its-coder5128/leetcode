class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        int MOD = 1e9 + 7;
        for(auto it:roads)
        {
            int u = it[0];
            int v = it[1];
            int cost = it[2];

            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }

        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> q;
        q.push({0,0});
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        ways[0] = 1;
        dist[0] = 0;

        int cnt = 0;

        while(!q.empty())
        {
            int node = q.top()[1];
            long long cost = q.top()[0];
            q.pop();

            for(auto it:adj[node])
            {
                if(dist[it.first] > cost + it.second)
                {

                    ways[it.first] = ways[node];
                    dist[it.first] = cost + it.second;
                    q.push({cost + it.second,it.first});
                }
                else if(dist[it.first] == cost + it.second)
                { 
                    long long sum = (long long)ways[it.first] + (long long)ways[node];
                    ways[it.first] = (sum)%MOD;
                }

            }
        }
        return ways[n-1]%MOD;
    }
};