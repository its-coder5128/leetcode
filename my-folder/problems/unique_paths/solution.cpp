class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);
        curr[n-1] = 1;

        swap(m,n);
       

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i == n-1 && j == m-1)
                    continue;
                int down = next[j];
                int right = curr[j+1];
                curr[j] = down + right;
            }
            next = curr;
        }

        return curr[0];
    }
};