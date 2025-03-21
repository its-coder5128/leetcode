class Solution {
public:
    string reverseWords(string s) {

        int i=0,j=0;

        while(j<s.size())
        {
            while(j<s.size() && s[j] != ' ')
            {
                j++;
            }

            reverse(s.begin()+i,s.begin()+j);

            i=j+1;
            j=i;
        }

        reverse(s.begin()+i,s.begin()+j);

        return s;
        
    }
};