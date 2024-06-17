class Solution {
public:
    char findExp(vector<bool> &exp,char op)
    {
        bool ans = exp[0];

        if(op == '!')
            return !ans;
        
        for(int i = 1;i<exp.size();i++)
        {
            if(op == '&')
                ans &= exp[i];
            else
                ans |= exp[i];
        }

        return ans;
    }
    bool solve(int& index,string& expression)
    {
        char op = expression[index];
        index += 2;

        vector<bool> exp;
        while(index < expression.size() && expression[index] != ')')
        {
            if(expression[index] == 't')
            {
                exp.push_back(true);
                index++;
            }
            else if(expression[index] == 'f')
            {
                exp.push_back(false);
                index++;
            }
            else if(expression[index] == ',')
                index++;
            else{
                exp.push_back(solve(index,expression));
            }
        }

        index++;

        return findExp(exp,op);

    }
    bool parseBoolExpr(string expression) {
        int index = 0;
        return  solve(index,expression);
    }
};