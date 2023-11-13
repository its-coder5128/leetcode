class Solution {
public:
    bool check(char c,string vowel)
    {
        for(int i = 0;i<vowel.size();i++)
        {
            if(c == vowel[i])
            {
                return true;
            }
        }
        
        return false;
    }
    string sortVowels(string s) {

        string vowel = "AEIOUaeiou";
        vector<int> freq(53,0);

        for(int i = 0;i<s.size();i++)
        {
            if(check(s[i],vowel))
                freq[s[i] - 'A']++;
        }

        int j = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(check(s[i],vowel))
            {
                while(freq[vowel[j]-'A'] == 0)
                    j++;
                s[i] = vowel[j];
                freq[vowel[j]-'A']--;
                
            }
        }
        
        return s;
        
    }
};