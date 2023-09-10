class Solution {
public:
    int countOrders(int n) {

        long long ans = 1;

        while(n)
        {
            ans = (ans * ( 2*n-1) * n) % 1000000007;
            n--;
        }

        return ans;
        
    }
};