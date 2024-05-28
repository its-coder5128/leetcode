class Solution {
public:
    bool strStr(string a, string b) {
        int n = a.size();
        int m = b.size();

        for(int i = 0;i+m <= n;i++)
        {
            if(a.substr(i,m) == b)
            {
                return 1;
            }
        }

        return 0;
       
    }




    int repeatedStringMatch(string a, string b) {

        if(a == b){
            return 1;
        }

        string st = a;
        int repeat = 1;

        while(st.length()<b.length()){
            st += a;
            repeat++;
        }

        if(strStr(st,b)==true){
            return repeat;
        }
    
        if(strStr(st+a,b)==true){
            return repeat+1;
        }
        else{
            return -1;
        }



    }
};