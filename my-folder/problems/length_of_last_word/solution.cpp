class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int j = s.size()-1;

        while(i>=0 && s[i] == ' ')
            i--;
        j = i;
        while(j>=0 && s[j] != ' ')
            j--;
        
        return i - j;
    }
};