class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
          {
            int m = grid.size();
            int n = grid[0].size();

        // Further optimization
            if(k >= m + n - 2)
                return m + n - 2;
        }
        
        vector<vector<uint8_t>> seen(grid.size(), vector<uint8_t>(grid[0].size(), 0));
        
        struct TPos {
            size_t PathLen = 0;
            int X = 0;
            int Y = 0;
            int Budget = 0;
        };
        
        std::queue<TPos> q;
        q.push(TPos{0, 0, 0, k});
        seen[0][0] = 1;
        
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            
            if (pos.X == grid.size() - 1 && pos.Y == grid[0].size() - 1) {
                return pos.PathLen;
            }
            
            for (const auto& [dx, dy] : std::vector<std::pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                const auto newX = pos.X + dx;
                const auto newY = pos.Y + dy;
                if (newX < 0 || newX == grid.size() || newY < 0 || newY == grid[0].size()) {
                    continue;
                }
                const int budget = pos.Budget - grid[newX][newY];
                if (budget < 0) {
                    continue;
                }
                const int spent = k - budget + 1;
                if (seen[newX][newY] && seen[newX][newY] <= spent) {
                    continue;
                }
                seen[newX][newY] = spent;
                q.push(TPos{pos.PathLen + 1, newX, newY, budget});
            }
        }
        
        return -1;
    }
};