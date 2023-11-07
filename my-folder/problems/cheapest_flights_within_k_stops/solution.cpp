class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int,list<pair<int,int>>> m;

        for(int i = 0;i<flights.size();i++)
        {
            m[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        queue<vector<int>> q;
        q.push({src,0,-1});

        vector<int> dist(n,INT_MAX);

        while(!q.empty())
        {
            vector<int> front = q.front();
            q.pop();

            for(auto nb : m[front[0]])
            {
                if(dist[nb.first] > front[1]+nb.second && front[2] + 1 <= k)
                {
                    dist[nb.first] = front[1]+nb.second;
                    q.push({nb.first,front[1]+nb.second,front[2]+1});
                }
            }
        }

        if(dist[dst] != INT_MAX)
            return dist[dst];
        return -1;
    }
};