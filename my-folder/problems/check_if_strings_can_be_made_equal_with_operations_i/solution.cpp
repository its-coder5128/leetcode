class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        if(s1[0] == s2[2])
            swap(s2[0],s2[2]);
        if(s1[1] == s2[3])
            swap(s2[1],s2[3]);
        
        if(s2 == s1)
            return true;
        
        return false;
        
    }
};