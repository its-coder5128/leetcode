class Solution {
public:
    bool pali(string& str)
    {
        int i = 0, j = str.size()-1;
        
        while(i<=j)
        {
            if(str[i] == str[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }

        return true;
    }
    string firstPalindrome(vector<string>& words) {

        for(auto str:words)
        {
            if(pali(str))
                return str;
        }

        return "";
        
    }
};