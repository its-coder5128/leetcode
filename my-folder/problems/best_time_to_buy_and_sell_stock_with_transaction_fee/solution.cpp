class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> next1(2,0);
        vector<int> curr(2,0);

        for(int index = prices.size() - 1;index>=0;index--)
        {
          
            curr[1] = max( - prices[index] + next1[0], next1[1]);
                
            curr[0] = max( prices[index] - fee + next1[1], next1[0]);
            
            next1 = curr;
        }
        return next1[1];
    }
};