class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,1);

        for(int i = 1;i<m;i++)
        {
            vector<int> curr(n,1);
            for(int i = 1;i<n;i++)
            {
                curr[i] = curr[i-1] + prev[i];
            }
            prev = curr;
        }

        return prev[n-1];
    }
};