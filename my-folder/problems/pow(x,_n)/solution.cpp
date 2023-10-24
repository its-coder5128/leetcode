class Solution {
public:
    double myPower(double x, int n)
    {
        if(n == 0)
            return 1;
        
        if(n&1)
            return x * myPower(x*x,n/2);
        else
            return myPower(x*x,n/2);
    }
    double myPow(double x, int n) {

        if( n >=0 )
            return myPower(x,n);
        else
            return 1/myPower(x,abs(n));

    }
};