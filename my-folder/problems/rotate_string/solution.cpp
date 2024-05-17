class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.size() != goal.size())
            return false;
        
        s += s;

        int i = 0;
        int j = 0;

        int n = s.size();
        int m = goal.size();

        while(i<n && j<m)
        {
            cout<<s[i]<<" "<<goal[j]<<endl;
            if(s[i] == goal[j])
            {
                j++;
            }
            else{
                j = 0;
                if(s[i] == goal[j])
                    j++;
            }
            i++;
        }

        return j == m;
    }
};