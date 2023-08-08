class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();

        vector<int> left(n);
        vector<int> right(n);

        int i = 0;
        int j = n - 1;

        while(i+1 < a.size() && a[i] < a[i+1])
        {
            i++;
        }
        while(j - 1 >= 0 && a[j] < a[j-1])
        {
            j--;
        }
        int x = j;

        int maxiL=INT_MIN;
        int maxiR=INT_MIN;

        for(int k = i;k<=j;k++)
        {
            maxiL = max(maxiL,a[k]);
            maxiR = max(maxiR,a[x]);

            left[k] = maxiL;
            right[x] = maxiR;
            x--;
        }

        int ans = 0;

        while(i<=j)
        {
            ans += min(left[i],right[i]) - a[i];

            i++;
        }

        return ans;
        
    }
};