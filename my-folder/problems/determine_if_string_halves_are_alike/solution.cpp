class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;

        int n = s.size();

        for(int i = 0;i<n;i++)
        {
            char c = s[i];
            if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
            {
                if(i<n/2)
                    cnt++;
                else{
                    cnt--;
                }
            }
        }

        return cnt == 0;
        
    }
};