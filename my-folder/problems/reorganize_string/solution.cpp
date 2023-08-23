class Solution {
public:
    string reorganizeString(string &s) {

        //string ans = s;

        bool firstLoop = true;

        for(int i = 0;i<s.size();i++)
        {
            if( s[i] == s[i+1])
            {
                bool flag = false;

                for(int j = i+2;j<s.size();j++)
                {
                    if(s[i+1] != s[j])
                    {
                        flag = true;
                        swap(s[i+1],s[j]);
                        break;
                    }
                }
                if(!flag)
                {
                    firstLoop = false;
                    break;
                }
                    
            }
            if(!firstLoop)
                break;
        }

        if(firstLoop)
            return s;

        reverse(s.begin(),s.end());
        
        for(int i = 0;i<s.size();i++)
        {
            if( s[i] == s[i+1])
            {
                bool flag = false;

                for(int j = i+2;j<s.size();j++)
                {
                    if(s[i+1] != s[j])
                    {
                        flag = true;
                        swap(s[i+1],s[j]);
                        break;
                    }
                }
                if(!flag)
                    return "";
            }
        }

        return s;

        


        
    }
};