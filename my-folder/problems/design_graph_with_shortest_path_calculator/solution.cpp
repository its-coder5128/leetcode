class Graph {
    vector<vector<pair<int,int>>> m;
    int tot_nodes;
public:
    Graph(int n, vector<vector<int>>& edges) {
        tot_nodes = n;
        m.resize(n);
        for(int i = 0;i<edges.size();i++)
        {
            m[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        m[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {

        vector<long long> cost(tot_nodes,INT_MAX);
        queue<int> q;
        q.push(node1);
        cost[node1] = 0;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto nb:m[front])
            {
                if(cost[nb.first] > cost[front] + nb.second)
                {
                    q.push(nb.first);
                    cost[nb.first] = cost[front] + nb.second;
                }
             }
        }

        if(cost[node2] < INT_MAX)
            return cost[node2];
        return -1;
        
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */