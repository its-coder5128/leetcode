class Solution {
public:
    int countHomogenous(string str) {

        int s = 0;
        int e = 0;

        int cnt = 0;
        int MOD = 1e9 + 7;
        while(e<str.size())
        {
            if(str[s] == str[e])
            {
                cnt = (cnt + e + 1 - s) % MOD;
                e++;
            }
            else{
                s = e;
            }
        }

        return cnt;


        
    }
};