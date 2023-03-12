class Solution {
public:
    string removeDuplicates(string s) {
        
        int len=s.length(),i=1;
        string temp;

        temp.push_back(s[0]);
        while(i<len)
        {
            if(temp.empty()==0)
            {
                if(temp.back()==s[i])
                {
                    temp.pop_back();
                }
                else
                temp.push_back(s[i]);
            }
            
            else
            temp.push_back(s[i]);

            i++;

        }

        
        return temp;
    }
};