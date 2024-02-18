class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0] < v2[0];
    }
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(),meetings.end(),sortcol);

        vector<int> cnt(n,0);
        vector<long long> occ(n,0);

        int maxi = INT_MIN;
        int ans = -1;

        for(int i = 0;i<meetings.size();i++)
        {
            long long mini = 1e18;
            int index = -1;

            for(int j = 0;j<n;j++)
            {
                if(occ[j] <= meetings[i][0])
                {
                    index = j;
                    break;
                }
                else if(occ[j] < mini)
                {
                    mini = occ[j];
                    index = j;
                }
            }
            occ[index] = max(occ[index],1ll*meetings[i][0]) + 1ll*(meetings[i][1] - meetings[i][0]);
            cnt[index]++;
        }

        for(int i = 0;i<n;i++)
        {
            if(cnt[i] > maxi)
            {
                maxi = cnt[i];
                ans = i;
            }
        }

        return ans;
    }
};