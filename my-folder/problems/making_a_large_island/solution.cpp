class Solution {
    class DisjointSet {
    public:
        vector<int> parent, size;
        DisjointSet(int n) {
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n*n);

        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                for(int k = 0;k<4;k++)
                {
                    int nr = i + dRow[k];
                    int nc = j + dCol[k];

                    if(nr >= 0 && nc >= 0 && nc < n && nr < n && grid[nr][nc] == 1 && grid[i][j] == 1)
                    {
                        int node = i * n + j;
                        int adjNode = nr * n + nc;

                        if(ds.findUPar(node) != ds.findUPar(adjNode))
                        {
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }
        int maxi = *max_element(ds.size.begin(),ds.size.end());
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    int sum = 1;
                    unordered_set<int> s;
                    for(int k = 0;k<4;k++)
                    {
                        int nr = i + dRow[k];
                        int nc = j + dCol[k];

                        if(nr >= 0 && nc >= 0 && nc < n && nr < n && grid[nr][nc] == 1)
                        {
                            int adjNode = nr * n + nc;

                            s.insert(ds.findUPar(adjNode));
                        }
                    }

                    for(auto it:s)
                    {
                        sum += ds.size[it];
                    }
                    maxi = max(sum,maxi);
                }
            }
        }
        return maxi;
    }
};