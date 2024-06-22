class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;

        int n = num.size();
        int size = n-k;

        for(int i = 0;i<n;i++)
        {
            int x = num[i] - '0';

            while(!st.empty() && st.top() > x && k > 0)
            {
                k--;
                st.pop();
            }
            
            st.push(x);
        }

        while(st.size() > size)
            st.pop();
        
        string ans = "";

        while(!st.empty())
        {
            ans += st.top() + '0';
            st.pop();
        }

        while(ans.size() > 0 && ans.back() == '0')
            ans.pop_back();

        reverse(ans.begin(),ans.end());

        if(ans.size() == 0)
            return "0";

        return ans;
    }
};