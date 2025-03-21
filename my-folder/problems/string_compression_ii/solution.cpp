int dp[101][101][27][101];
class Solution {
private:
    int f(int idx,int k,int prev,int prev_cnt,string& s) {
        //base cases
        if(k < 0) return 1e9;
        if(idx == s.length()) return 0;
        if(dp[idx][k][prev][prev_cnt] != -1) return dp[idx][k][prev][prev_cnt];

        int notTake = 0 + f(idx+1,k-1,prev,prev_cnt,s);
        int take=0;
        if(s[idx] == (prev+'a')) {
            take = f(idx+1,k,prev,prev_cnt+1,s);
            take += (prev_cnt==1 || prev_cnt==9 || prev_cnt==99);
        }
        else {
            take = 1 + f(idx+1,k,s[idx]-'a',1,s);   
        }
        return dp[idx][k][prev][prev_cnt] = min(take,notTake);;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,k,26,0,s); // 26 for '{'
    }
    
};