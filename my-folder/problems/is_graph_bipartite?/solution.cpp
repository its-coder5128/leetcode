class Solution {
public:
    bool is_Bupartite(vector<vector<int>>& graph,int node,int parent,vector<int>& color)
    {
        if(parent == -1)
            color[node] = 0;
        else
            color[node] = !color[parent];

        for(auto nb : graph[node])
        {
            if(color[nb] == -1)
            {
                if(!is_Bupartite(graph,nb,node,color))
                    return false;
            }
            else if(nb != parent && color[nb] == color[node])
                return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector<int> color(n,-1);

        for(int i = 0;i<n;i++)
        {
            if(color[i] == -1)
            {
                
                if(is_Bupartite(graph,i,-1,color) == false)
                    return false;
            }
        }

        return true;
    }
};