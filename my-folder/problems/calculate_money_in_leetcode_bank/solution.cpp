class Solution {
public:
    int totalMoney(int n) {
        
        int x = n/7;
        int y = n%7;

        return (28 * x) + (((x)*(x-1))/2)*7 + ((y)*(2*x + y + 1))/2;
        
    }
};