class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        while(i<n && s[i] == ' ')
            i++;
        
        bool flag = 0;
        if(s[i] == '-')
        {
            flag = 1;
            i++;
        }
        else if(s[i] == '+')
        {
            i++;
        }

        long long int ans = 0;
        
        while(i<n && s[i] <= '0' + 9 && s[i] >= '0')
        {
            long long int x = s[i] - '0';

            if(ans*10 + x > INT_MAX + 1ll*200)
            {
                ans = ans*10 + x;
                break;
            }
            ans = ans*10 + x;
            i++;
        }

        if(flag)
        {
                ans = -ans;
        }
        
        if(ans > INT_MAX)
            return INT_MAX;
        else if(ans < INT_MIN)
            return INT_MIN;
        return ans;
        
    }
};