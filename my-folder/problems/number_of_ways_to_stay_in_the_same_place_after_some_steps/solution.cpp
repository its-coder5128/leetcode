class Solution {
public:
    int numWays(int steps, int arrLen) {

        int n = min(arrLen,(steps/2)+1);

        vector<int> curr(n,0);
        vector<int> prev(n,0);
        prev[0] = 1;

        for(int m = 1;m<=steps;m++)
        {
            for(int index = n-1;index>=0;index--)
            {
                int stay = prev[index]%1000000007;
                int left = 0;
                if(index-1>=0)
                    left = prev[index-1]%1000000007;
                int right = 0;
                if(index+1<n)
                    right = prev[index+1]%1000000007;
                
                curr[index]=((stay+left)%1000000007+right)%1000000007;
            }
            prev = curr;
        }
        return curr[0];

    }
};