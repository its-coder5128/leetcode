class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[0] < b[0])
            return true;
        else if(a[0] == b[0] && a[1] < b[1])
            return true;
        return false;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();

        vector<vector<int>> arr(n,vector<int>(2,0));
        int maxi = 0;

        for(int i = 0;i<n;i++)
        {
            arr[i][0] = difficulty[i];
            arr[i][1] = profit[i];
        }

        sort(arr.begin(),arr.end(),cmp);
        vector<int> temp(n,0);
        for(int i= 0;i<n;i++)
        {
            temp[i] = arr[i][0];
            maxi = max(maxi,arr[i][1]);
            arr[i][1] = maxi;

        }
        int ans = 0;
        for(int i = 0;i<m;i++)
        {
            int x = worker[i];

            int index = upper_bound(temp.begin(),temp.end(),x) - temp.begin() - 1;

            // cout<<index<<endl;

            if(index >= 0 && index <n)
                ans += arr[index][1];
        }

        return ans;
    }
};