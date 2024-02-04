class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi = 0;
        stack<int> st;
        st.push(-1);

        for(int i = 0;i<s.size();i++)
        {
            int t = st.top();

            if(t != -1 && s[t] == '(' && s[i] == ')')
            {
                st.pop();
                maxi = max(maxi,i - st.top());
            }
            else
                st.push(i);
        }

        return maxi;
        
    }
};