class Solution {
public:
    int poorPigs(int buckets, int x, int y) {

        
        int T = y/x+1;
        int t = T;
        int n = buckets;

        if(n == 1)
            return 0;

        int i = 1;

        while(1)
        {
            if(T>=n)
                break;
            
            T *= t;
            i++;

            //cout<<T<<" "<<i<<endl;
        }

        return i;

        
    }
};