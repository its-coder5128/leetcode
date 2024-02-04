class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> charCount('z'-'A'+1,0);
        int requiredChars = t.size();
        int i = 0, j = 0, minLength = INT_MAX, minStart = 0;

        for (char c : t) {
            charCount[c - 'A']++;
        }

        while (j < s.size()) {
            if (charCount[s[j]-'A'] > 0) {
                requiredChars--;
            }
            charCount[s[j]-'A']--;
            j++;

            while (requiredChars == 0) {
                if (j - i < minLength) {
                    minLength = j - i;
                    minStart = i;
                }
                charCount[s[i]-'A']++;
                if (charCount[s[i]-'A'] > 0) {
                    requiredChars++;
                }
                i++;
            }
        }

        return (minLength == INT_MAX) ? "" : s.substr(minStart, minLength);
    }
};
