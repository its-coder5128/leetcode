class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string str = countAndSay(n-1);

        int cnt = 0;
        string nstr = "";

        for(int i = 0;i<str.size()-1;i++)
        {
            if(str[i] == str[i+1])
                cnt++;
            else
            {
                cnt++;
                nstr += to_string(cnt) + str[i];
                cnt=0;
            }
        }

        cnt++;
        nstr += to_string(cnt) + str[str.size()-1];

        return nstr;
        
    }
};