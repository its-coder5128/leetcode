class Solution {
public:
    long long check(vector<int>& piles, int x)
    {
        long long ans = 0;

        for(auto it:piles)
        {
            ans += (long long)(it/x) + (long long)(it%x != 0);
        }

        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = 0;

        for(auto it:piles)
            e = max(e,it);
        
        while(s<=e)
        {
            int m = s + (e-s)/2;

            long long hoursTaken = check(piles,m);

            if(hoursTaken > h)
                s = m + 1;
            else
                e = m - 1;
        }

        return s;
    }
};