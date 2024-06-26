class Solution {
public:
    void solve(vector<int>& jobs, int k,int index,vector<int>& workers,int m,int &ans)
    {
        if(index == jobs.size())
        {
            ans = min(ans,m);
            return ;
        }

        if(m >= ans)
            return;


        for(int i = 0;i<k;i++)
        {
            if(i > 0 && workers[i] == workers[i-1])
                continue;
            workers[i] += jobs[index];
            int t = m;
            m = max(m,workers[i]);

            solve(jobs,k,index+1,workers,m,ans);

            workers[i] -= jobs[index];
            m = t;
        }

        return;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> workers(k,0);
        int ans = INT_MAX;
        int m = INT_MIN;
        sort(jobs.rbegin(), jobs.rend());
        solve(jobs,k,0,workers,m,ans);
        return ans;
    }
};