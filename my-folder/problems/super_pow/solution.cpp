class Solution {
public:
    int pow_int(int a,int b)
    {
        int x=1;
        a=a%1337;

        for(int i=0;i<b;i++)
        {
            x = (x*a) % 1337;
        }

        return x;
    }
    int superPow(int a, vector<int>& b) {

        if(b.empty())
        {
            return 1;
        }

        int last_digit=b[b.size()-1];
        b.pop_back();

        return pow_int(superPow(a,b),10) * pow_int(a,last_digit) % 1337;
        
    }
};