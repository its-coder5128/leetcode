class Solution {
public:
    string minWindow(string s, string t) {

        int i=0;
        int j=0;
        int mini = INT_MAX;

        unordered_map<char,int> m;
        int head=i;

        for(auto x:t)
        {
            m[x]++;
        }
        int counter = t.size();

        while(j<s.size())
        {
            if(m[s[j]]>0)
                counter--;
            
            m[s[j]]--;
            j++;

            if(counter == 0)
            {
                while(counter == 0)
                {
                    if(mini > j-i)
                    {
                        head = i;
                        mini = j-i;
                    }


                    m[s[i]]++;
                    if(m[s[i]] > 0)
                        counter++;
                    i++;
                }
            }
        }
        if(mini == INT_MAX)
            return "";
        
        cout<<head<<" "<<mini<<s.substr(head,mini);
        return s.substr(head,mini);
        
    }
};