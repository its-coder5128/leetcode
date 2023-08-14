class Solution {
public:
    string convert(string s, int numRows) {

        vector<string> str(numRows);

        if(numRows <= 1 || s.size() <= 1)
            return s;

        int i=0;
        int j=0;

        while(i<s.size())
        {
            while(i<s.size() && j<numRows-1)
            {
                str[j] += s[i];
                i++;
                j++;
            }

            while(i<s.size() && j>0)
            {
                str[j] += s[i];
                i++;
                j--;
            }
        }

        string ans="";

        for(int i=0;i<numRows;i++)
        {
            ans += str[i];
        }

        return ans;
    }
};