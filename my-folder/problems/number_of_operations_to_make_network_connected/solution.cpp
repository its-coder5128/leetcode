class Solution {
    class disJoinSet
    {
        vector<int> size;
        vector<int> parent;
        
        public:
        disJoinSet(int n)
        {
            size.resize(n+1);
            parent.resize(n+1);
            
            for(int i = 0;i<=n;i++)
            {
                size[i] = 1;
                parent[i] = i;
            }
        }
        
        int findParent(int x)
        {
            if(parent[x] == x)
                return x;
            
            return parent[x] = findParent(parent[x]);
        }
        
        void unionBySize(int x,int y)
        {
            int par_x = findParent(x);
            int par_y = findParent(y);
            
            if(par_x == par_y)
                return;
            
            if(size[par_x] > size[par_y])
            {
                parent[par_y] = par_x;
                size[par_x] += size[par_y];
            }
            else
            {
                parent[par_x] = par_y;
                size[par_y] += size[par_x];
            }
            return;
        }

        int findComp(int n)
        {
            int comp = 0;
            for(int i = 0;i<n;i++)
            {
                if(parent[i] == i)
                    comp++;
            }

            return comp;
        }
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();

        if(m < n-1)
            return -1;

        disJoinSet DJS(n);

        for(int i = 0;i<connections.size();i++)
            DJS.unionBySize(connections[i][0],connections[i][1]);
        
        return DJS.findComp(n) - 1;
    }
};