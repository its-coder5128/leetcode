class Solution {
public:
    struct hashFunction 
    { 
        size_t operator()(const pair<int ,  
                            int> &x) const
        { 
            return x.first ^ x.second; 
        } 
    }; 
    bool isPathCrossing(string path) {
        unordered_set<pair<int,int>,hashFunction> st;
        int x=0,y=0;
        st.insert({x,y});

        for(int i = 0;i<path.size();i++)
        {
            if(path[i] == 'N') y++;
            else if(path[i] == 'S') y--;
            else if(path[i] == 'E') x++;
            else if(path[i] == 'W') x--;

            if(st.find({x,y}) != st.end())
                return true;
            
            st.insert({x,y});
        }

        return false;
        
    }
};