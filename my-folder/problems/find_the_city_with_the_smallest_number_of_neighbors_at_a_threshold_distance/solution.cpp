class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        for(auto it:edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int i = 0;i<n;i++)
            dist[i][i] = 0;
        
        for(int via = 0;via<n;via++)
        {
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    dist[i][j] = min(dist[i][j],dist[i][via] + dist[via][j]);
                }
            }
        }
        int ans = -1;
        int mini = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            int cnt = 0;
            for(int j = 0;j<n;j++)
            {   
                if(dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            if(cnt <= mini)
            {
                mini = cnt;
                ans = i;
            }
        }

        return ans;
    }
};