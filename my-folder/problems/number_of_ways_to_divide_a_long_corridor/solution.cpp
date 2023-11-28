class Solution {
public:
    int numberOfWays(string corridor) {

        int ans = 1;
        int i = 0;
        while(i<corridor.size())
        {
            int cnt = 0;
            while(i<corridor.size() && cnt < 2)
            {
                if(corridor[i] == 'S')
                    cnt++;
                i++;
            }
            if(cnt<2)
                return 0;
            int divisions = 0;
            while(i<corridor.size() && corridor[i] == 'P')
            {
                i++;
                divisions++;
            }
            if(i == corridor.size())
                break;
            ans = ((long long)ans * (long long)(divisions+1)) % (1000000007);
        }

        return ans;
        
    }
};