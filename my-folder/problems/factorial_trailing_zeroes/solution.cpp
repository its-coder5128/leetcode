class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;

        for(int i=1;i<=n;i++)
        {
            int j=i;
            while(j>4 && j%5==0)
            {
                cnt++;
                j = j/5;
            }
        }

        return cnt;
        
    }
};