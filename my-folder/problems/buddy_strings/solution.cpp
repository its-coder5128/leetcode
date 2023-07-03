class Solution {
public:
    bool buddyStrings(string s, string goal) {

        int len1=s.size();
        int len2=goal.size();

        if(len1 != len2 || len1<2)
        {
            return false;
        }

        vector<int> diff;

        for(int i=0;i<len1;i++)
        {
            if(s[i] != goal[i])
            {
                diff.push_back(i);
            }
        } 

        if(diff.size()%2 == 1 || diff.size() > 2)
        {
            return false;
        }

        if(diff.size() == 2)
        {
            swap(s[diff[0]],s[diff[1]]);
            if(s == goal)
                return true;
            else
                return false;
        }

        unordered_map<char,int> m;    

        for(int i=0;i<len1;i++)
        {
            if(m.count(s[i])>0)
            {
                return true;
            }

            m[s[i]]++;
        }

        return false;    
        
    }
};