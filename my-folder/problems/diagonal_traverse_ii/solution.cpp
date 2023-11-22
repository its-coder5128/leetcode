class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        int mRow = nums.size();

        vector<vector<int>> vis = nums;

        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 0;

        vector<int> ans;

        while(!q.empty())
        {
            int n = q.size();

            for(int i = 0;i<n;i++)
            {
                auto front = q.front();
                q.pop();

                int row = front.first;
                int col = front.second;

                ans.push_back(nums[row][col]);
                
                if(row + 1 < mRow && col < nums[row+1].size() && vis[row+1][col] != 0)
                {
                    vis[row+1][col] = 0;
                    q.push({row+1,col});
                }

                if(col + 1 < nums[row].size() && vis[row][col+1] != 0)
                {
                    vis[row][col+1] = 0;
                    q.push({row,col+1});
                }

            }
        }

        return ans;
        
    }
};