class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini = prices[0];
        int n = prices.size();

        for(int i = 1;i<n;i++)
        {
            if(mini > prices[i])
                mini = prices[i];
            else{
                maxi = max(maxi,prices[i] - mini);
            }
        }

        return maxi;
    }
};