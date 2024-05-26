class Solution {
public:
    string compressedString(string word) {
        
        string comp = "";
        
        int i = 0;
        int j = 0;
        int n = word.size();
        
        while(i<n && j<n)
        {
            int cnt = 0;
            while(j<n && word[i] == word[j] && cnt < 9)
            {
                cnt++;
                j++;
            }
            comp += '0' + cnt;
            comp += word[i];
            
            i = j;
            
        }
        
        return comp;
        
    }
};