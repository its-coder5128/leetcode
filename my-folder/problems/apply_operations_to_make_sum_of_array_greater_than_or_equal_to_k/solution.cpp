class Solution {
public:
    int minOperations(int k) {
        if(k<=1)
            return 0;

        int ans = 1e9;
        
        for(int i = 1;i<=k;i++)
        {
            ans = min(ans,(k - 1)/i + i - 1);
        }
        
        return ans;
    }
};