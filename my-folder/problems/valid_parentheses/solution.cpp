class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto it:s)
        {
            if(it == '(' || it == '{' || it == '[')
                st.push(it);
            else{
                char c;
                if(!st.empty())
                    c = st.top();
                else
                    return false;
                if((it == ')' && c == '(') || (it == '}' && c == '{') || (it == ']' && c == '['))
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};