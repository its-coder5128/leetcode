class Solution {
public:
    int reverse(int x) {

        long long y;

        int newX = abs(x);

        while(newX > 0)
        {
            y = y*10 + newX%10;

            newX = newX / 10;
        }

        if(x<0)
            y = -y;
        
        if(y>INT_MAX || y<INT_MIN)
            return 0;
        
        return y;

        
    }
};