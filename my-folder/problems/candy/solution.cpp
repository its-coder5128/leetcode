class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int ans = 1;
        int i = 1;

        while(i<n)
        {
            if(ratings[i] == ratings[i-1])
            {
                ans++;
                i++;
                continue;
            }

            int peak = 1;
            while(i<n && ratings[i] > ratings[i-1])
            {
                peak++;
                ans += peak;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i] < ratings[i-1])
            {
                ans += down;
                down++;
                i++;
            }
            if(down > peak)
                ans = ans - peak + down;
        }

        return ans;
    }
};