class Solution {
public:
    static int numOfbits(int a)
    {
        int cnt = 0;

            for(int j = 0;j<32;j++)
            {
                if(a & (1<<j))
                    cnt++;
            }
        
        return cnt;
    }
    static bool cmp(int &a,int &b)
    {
        int x = numOfbits(a);
        int y = numOfbits(b);
        
        if(x == y)
            return a<b;
        
        return x<y;
    }
    vector<int> sortByBits(vector<int>& arr) {

        

        sort(arr.begin(),arr.end(),cmp);

    

        return arr;
            
        
    }
};