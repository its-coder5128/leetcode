class Solution {
    class disJoinSet
    {
        vector<int> size;
        vector<int> parent;
        int comp;
        
        public:
        disJoinSet(int n)
        {
            size.resize(n+1);
            parent.resize(n+1);
            comp = n;
            
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
            
            comp--;

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

        int findComp()
        {
            return comp;
        }
    };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        disJoinSet DJS(n);

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(isConnected[i][j] == 1)
                    DJS.unionBySize(i,j);
            }
        }
        
        return DJS.findComp();
    }
};