class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        
        if(purchaseAmount % 10 == 0)
            return 100 - purchaseAmount;
        
        if(purchaseAmount % 10 < 5 )
        {
            int x = purchaseAmount / 10;
        
            int nearest = 10 + 10*(x-1);

            return 100-nearest;
        }
        else{
            int x = purchaseAmount / 10;
        
            int nearest = 10 + 10*x;

            return 100-nearest;
        }
        
        
    }
};