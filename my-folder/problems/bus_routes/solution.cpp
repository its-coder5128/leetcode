class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
        if(s == t)
            return 0;

        unordered_map<int,vector<int>> m;
        bool sp = false,tp = false;
        for(int i = 0;i<routes.size();i++)
        {
            for(auto stops:routes[i])
            {
                m[stops].push_back(i);
                if(stops == s)
                    sp = true;
                else if(stops == t)
                    tp = true;
            }
        }

        unordered_set<int> vis_route;
        unordered_set<int> vis_stops;
        queue<int> q;
        q.push(s);

        int cnt = 0;

        while(!q.empty())
        {
            int n = q.size();
            cnt++;
            for(int i = 0;i<n;i++)
            {
                int f = q.front();
                vector<int> front = m[f];
                q.pop();

                for(auto route:front)
                {
                    if(vis_route.count(route))
                        continue;
                    vis_route.insert(route);
                    for(int j = 0;j<routes[route].size();j++)
                    {
                        if(vis_stops.count(routes[route][j]))
                            continue;
                        vis_stops.insert(routes[route][j]);
                        if(routes[route][j] == t)
                            return cnt;
                        q.push(routes[route][j]);
                    }
                }
            }
        }

        return -1;
        
    }
};