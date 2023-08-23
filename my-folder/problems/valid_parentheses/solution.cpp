class Solution {
public:
    bool isValid(string s) {

        stack<int> stk;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(s[i]);
            
            if(s[i] == ')')
            {
                if(stk.empty())
                    return false;
                if(stk.top() == '(')
                    stk.pop();
                else
                    return false;
            }
            else if(s[i] == '}')
            {
                if(stk.empty())
                    return false;
                if(stk.top() == '{')
                    stk.pop();
                else
                    return false;
            }
            else if(s[i] == ']')
            {
                if(stk.empty())
                    return false;
                if(stk.top() == '[')
                    stk.pop();
                else
                    return false;
            }
        }

        if(stk.empty())
            return true;
        return false;
    }
};