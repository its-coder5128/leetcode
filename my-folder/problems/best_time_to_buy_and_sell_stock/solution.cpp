class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxi = 0;

        for(int i=0;i<prices.size();i++)
        {
            buy = min(buy,prices[i]);

            if(prices[i] > buy)
            {
                maxi = max(maxi , prices[i] - buy);
            }
        }

        return maxi;



        
    }
};