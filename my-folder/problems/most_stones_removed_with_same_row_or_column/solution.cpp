class Solution {
    class disJointSet
    {
        vector<int> size;
        vector<int> parent;
        
        public:
        disJointSet(int n)
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

        int canRemove(int n)
        {
            int ans = 0;

            for(int i = 0;i<n;i++)
            {
                if(parent[i] == i)
                    ans += size[i] - 1;
            }

            return ans;
        }

    };
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();

        disJointSet ds(n);
        unordered_map<int,int> row;
        unordered_map<int,int> col;

        for(int i = 0;i<n;i++)
        {
            
            
                if(row.find(stones[i][0]) != row.end() )
                {
                    ds.unionBySize(i,row[stones[i][0]]);
                }
                if(col.find(stones[i][1]) != col.end())
                    ds.unionBySize(i,col[stones[i][1]]);
                
                row[stones[i][0]] = i;
                col[stones[i][1]] = i;
        }

        return ds.canRemove(n);
    }
};