class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<int> cities(n,0);
        set<pair<int,int>> road_set;

        for(int i=0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];

            road_set.insert({u,v});
            road_set.insert({v,u});

            cities[u]++;
            cities[v]++;
        }

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int rank = cities[i] + cities[j];
                if(road_set.find({i,j}) != road_set.end())
                    rank = rank - 1;

                ans = max(ans,rank);
            }
        }

        

        return ans;


        
    }
};