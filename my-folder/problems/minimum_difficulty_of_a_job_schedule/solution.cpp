class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {

        int n = jd.size();
        if(d>n)
            return -1;

        vector<int> prev(n+1,1e9);
        vector<int> curr(n+1,1e9);

        prev[n-1] = jd[n-1];

        for(int i = n-2 ;i>=0;i--)
        {
            prev[i] = max(jd[i],prev[i+1]);
        }

        for(int day=2;day<=d;day++)
        {
            for(int index = n-1;index>=0;index--)
            {
                int ans = 1e9;
                int maxi = INT_MIN;
                for(int i  = index;i<n;i++)
                {
                    maxi = max(maxi,jd[i]);
                    ans = min(ans,maxi + prev[i+1]);
                }

                curr[index] = ans;
            }
            prev = curr;
        }

        return prev[0];

    }
};