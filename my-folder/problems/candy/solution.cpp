class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> candy(n,1);
        int sum = 0;

        for(int i=0;i<n;i++)
        {
            int maxi = 0;
            if(i-1 >= 0 && ratings[i] > ratings[i-1])
            {
                maxi = max(maxi,candy[i-1]);
            }
            if(i+1 < n && ratings[i] > ratings[i+1])
            {
                maxi = max(maxi,candy[i+1]);
            }
            candy[i] = maxi + 1;
        }
        for(int i=n-1;i>=0;i--)
        {
            int maxi = 0;
            if(i-1 >= 0 && ratings[i] > ratings[i-1])
            {
                maxi = max(maxi,candy[i-1]);
            }
            if(i+1 < n && ratings[i] > ratings[i+1])
            {
                maxi = max(maxi,candy[i+1]);
            }

            candy[i] =max(maxi + 1,candy[i]);
            sum += candy[i];
        }
        return sum;
        
    }
};