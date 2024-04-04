class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxi = 0;

        for(auto c : s)
        {
            if(c == '(')
            {
                cnt++;
                maxi = max(cnt,maxi);
            }
            else if(c == ')'){
                cnt--;
            }
        }

        return maxi;
    }
};