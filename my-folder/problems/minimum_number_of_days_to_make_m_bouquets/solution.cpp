class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k,int mid)
    {
        int totCnt = 0;
        int cnt = 0;
        int n = bloomDay.size();

        for(int i = 0;i<n;i++)
        {
            if(bloomDay[i] > mid)
                cnt = 0;
            else
            {
                cnt++;
                if(cnt == k)
                {
                    totCnt++;
                    cnt = 0;
                }
            }

            if(totCnt == m)
                return true;
        }

        return false;


    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int s = 1;
        int e = *max_element(bloomDay.begin(),bloomDay.end());

        if((long long)((long long)m*(long long)k) > (long long)bloomDay.size())
            return -1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(possible(bloomDay,m,k,mid))
                e = mid - 1;
            else
                s = mid + 1;
        }

        return s;
        
    }
};