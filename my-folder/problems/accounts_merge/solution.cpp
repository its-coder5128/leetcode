class Solution {
public:
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

        int canRemove(int n)
        {
            int cnt = 0;

            for(int i = 0;i<n;i++)
            {
                if(parent[i] == i)
                    cnt += size[i]-1;
            }

            return cnt;
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        disJoinSet DJS(n);

        unordered_map<string,int> m;

        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<accounts[i].size();j++)
            {
                if(m.find(accounts[i][j]) != m.end())
                {
                    DJS.unionBySize(i,m[accounts[i][j]]);
                }
                else{
                    m[accounts[i][j]] = i;
                }
            }
        }

        vector<string> arr[n];

        for(auto it:m)
        {
            int node = DJS.findParent(it.second);
            arr[node].push_back(it.first);
        }

        vector<vector<string>> ans;

        for(int i = 0;i<n;i++)
        {
            if(arr[i].size() > 0)
            {
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                sort(arr[i].begin(),arr[i].end());
                for(int j = 0;j<arr[i].size();j++)
                {
                    temp.push_back(arr[i][j]);
                }

                ans.push_back(temp);
            }
        }

        return ans;
    }
};