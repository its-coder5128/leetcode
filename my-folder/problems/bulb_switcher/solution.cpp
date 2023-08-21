class Solution {
public:
    int totFactors(int i)
    {
        if(i == 1)
            return 1;
        
        int count = 1;

        int c = 2;

        while(c<=i)
        {
            if(i%c == 0)
            {
                count++;
                // while(i%c==0)
                // {
                //     i = i/c;
                // }
            }

            c++;

        }

        return count;
    }
    int bulbSwitch(int n) {
       return sqrt(n);
    }
};