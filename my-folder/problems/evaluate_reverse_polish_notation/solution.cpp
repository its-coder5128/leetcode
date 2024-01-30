class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s;

        for(int i = 0;i<tokens.size();i++)
        {
            if(tokens[i].size() == 1 and tokens[i][0] < 48)
            {
                int second = s.top(); s.pop();
                int first = s.top(); s.pop();

                if(tokens[i][0] == '+')
                    s.push(first + second);
                else if(tokens[i][0] == '-')
                    s.push(first - second);
                else if(tokens[i][0] == '*')
                    s.push(first * second);
                else
                    s.push(first / second);

            }
            else{
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();
        
    }
};