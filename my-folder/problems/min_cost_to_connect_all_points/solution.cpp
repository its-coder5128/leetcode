class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> inMST(n);

        int cost = 0;
        int edgesUsed = 0;
        pq.push({0, 0});

        while (edgesUsed < n) {
            pair<int, int> top = pq.top();
            pq.pop();

            int weight = top.first;
            int node = top.second;

            if (inMST[node]) {
                continue;
            }

            inMST[node] = true;
            cost += weight;
            edgesUsed++;

            for (int nextNode=0; nextNode < n; ++nextNode) {
                if (!inMST[nextNode]) {
                    int nextWeight = abs(points[node][0] - points[nextNode][0]) + 
                                     abs(points[node][1] - points[nextNode][1]);

                    pq.push({nextWeight, nextNode});
                }
            }
        }
        return cost;
    }
};   