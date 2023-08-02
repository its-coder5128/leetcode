// class Solution {
// public:
//     string reverseWords(string s) {
//         stack<string> stk;
//        s +=" "; 

//         string ans="";

//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i] == ' ')
//             {
//                 stk.push(ans);
//                 ans = "";
//                 while(s[i] == ' ')
//                     i++;
                
//             }

//             ans += s[i];

//         }

//         //int j=0;
//         ans="";
//         while(!stk.empty() ){
//             string temp = stk.top();
//             stk.pop();

//             for(int i=0;i<temp.size();i++)
//             {
//                 ans += temp[i];
//             }
//             ans += ' ';
            
            
//         }

//         while(ans.back() == ' ')
//         {
//             ans.pop_back();
//         }
//         return ans;


//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        s+=" ";
        for(int i=0;i<s.length();i++){
            string temp="";
            if(s[i]==' '){
                continue;
            }
            while(i<s.length() && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            st.push(temp);
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top()+" ";
            st.pop();
        }
        return ans.substr(0,ans.size()-1);
    }
};

