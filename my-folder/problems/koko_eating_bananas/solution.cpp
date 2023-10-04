class Solution {
public:
    bool possible(vector<int>& piles, int h,int k)
    {
        int cnt = 0;
        for(int i=0;i<piles.size();i++)
        {
            int x = piles[i]/k;
            if(piles[i]%k)
                x++;
            cnt += x;
        }

        if(cnt<=h)
            return true;
        
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = -1;

        for(auto num : piles)
        {
            maxi = max(maxi,num);
        }
        
        int s = 1;
        int e = 1e9;

        while(s<e)
        {
            int mid = s + (e-s)/2;

            if(possible(piles,h,mid))
            {
                e = mid;
            }
            else
                s = mid + 1;
        }

        return s;
    }
};