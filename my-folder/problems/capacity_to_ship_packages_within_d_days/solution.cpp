class Solution {
public:
    int daysNeeded(vector<int>& weights, int shipCap)
    {
        int days = 0;
        int weigth = 0;
        int n = weights.size();

        for(int i = 0;i<n;i++)
        {
            weigth += weights[i];

            if(weigth > shipCap)
            {
                days++;
                weigth = weights[i];
            }
        }

        return days+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int s = *max_element(weights.begin(),weights.end());
        int e = s*weights.size();

        while(s<=e)
        {
            int m = s + (e-s)/2;

            if(daysNeeded(weights,m) <= days)
                e = m - 1;
            else
                s = m + 1;
        }

        return s;
    }
};