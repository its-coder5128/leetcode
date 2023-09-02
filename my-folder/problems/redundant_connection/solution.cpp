class Solution {
public:
    int find(int node,vector<int> &parent)
    {
        if(parent[node] == node)
            return node;
        
        return parent[node]=find(parent[node],parent);
    }
    bool unionn(int u,int v,vector<int> &parent,vector<int> &rank)
    {
        int parU = find(u,parent);
        int parV = find(v,parent);

        if(parU == parV)
            return true;

        if(rank[parU]>rank[parV])
            parent[parV] = parU;
        else if(rank[parU]<rank[parV])
            parent[parU] = parV;
        else
        {
            parent[parV] = parU;
            rank[parU]++;
        }


        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        vector<int> parent(edges.size(),0);
        vector<int> rank(edges.size(),0);

        for(int i=0;i<edges.size();i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;

            if(unionn(u,v,parent,rank))
                return {u+1,v+1};
        }

        return {-1,-1};
        
    }
};