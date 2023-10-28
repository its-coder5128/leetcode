class Solution {
public:
    int minChanges(string s) {
        
        int  i = 0;
        
        int op = 0;
        
        while(i<s.size())
        {
            char c = s[i];
            int cnt = 0;
            
            while(i<s.size() && c == s[i])
            {
                i++;
                cnt++;
            }
            
            if(cnt & 1)
            {
                op++;
                i++;
            }
            
        }
        
        return op;
        
    }
};