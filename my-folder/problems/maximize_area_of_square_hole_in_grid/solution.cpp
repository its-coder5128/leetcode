class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        int hmax = 2;
        int vmax = 2;
        
        int cnt = 1;
        
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        
        for(int i = 0;i<hBars.size()-1;i++)
        {
            if(hBars[i] == hBars[i+1]-1)
                cnt++;
            else
            {
                hmax = max(cnt+1,hmax);
                cnt = 1;
            }
        }
        hmax = max(cnt+1,hmax);
        cnt = 1;
        for(int i = 0;i<vBars.size()-1;i++)
        {
            if(vBars[i] == vBars[i+1]-1)
                cnt++;
            else
            {
                vmax = max(cnt+1,vmax);
                cnt = 1;
            }
        }
        vmax = max(cnt+1,vmax);
        
        long long ans = (long long)min(vmax,hmax) * (long long)min(vmax,hmax);
        
        return ans;
        
        
    }
};