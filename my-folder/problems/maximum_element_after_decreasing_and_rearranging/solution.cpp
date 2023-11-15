class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        int n = arr.size();

        vector<int> counter(n+1,0);

        for(int i = 0;i<n;i++)
        {
            ++counter[min(arr[i],n)];
        }

        int cnt = 0;
        int maxi = 1;

        for(int i = 1;i<=n;i++)
        {
            maxi = min(maxi + counter[i],i);
            
                cnt += counter[i];
                if(cnt == n)
                    break;
            
        }
        return maxi;
    }
};