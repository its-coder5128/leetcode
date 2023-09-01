// class Solution {
// public:
//     int myAtoi(string s) {
        
//         int n=s.size();
//         if(n == 0)
//             return 0;
//         int end=0;
//         int start=0;
//         long long ans = 0;
//         string temp="";
//         for(int i=0; i<n; i++)
//         {
//             if((s[i]<58 && s[i]>47) || s[i] == '-')
//             {
//                 temp.push_back(s[i]);
//             }
//             else if(s[i] == ' ')
//             {
//                 continue;
//             }
//             else
//             {
//                 if(temp.empty() || temp[0] == '-')
//                 {
//                     return 0;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//         }

//         ans = stol(temp);
//         if(ans < pow(-2,31))
//         {
//             return pow(-2,31);
//         }
//         else if(ans > pow(2,31) - 1)
//         {
//             return pow(2,31) - 1;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        while(s[i] == ' '){ // skipping space characters at the beginning
            i++;
        }

        int positive = 0, negative = 0; 

        if(s[i] == '+'){
            positive++; // number of positive signs at the start in string
            i++;
        }

        if(s[i] == '-'){
            negative++; // number of negative signs at the start in string
            i++;
        }

        double ans = 0; 

        while(i<n and s[i] >= '0' and s[i] <= '9'){
            ans = ans*10 + (s[i] - '0'); // (s[i] - '0') is converting character to integer
            i++;
        }

        if(negative > 0) // if negative sign exist
            ans = -ans;
        if(positive > 0 and negative > 0) // if both +ve and -ve sign exist, Example: +-12
            return 0;

        if(ans > INT_MAX) // if ans > 2^31 - 1
            ans = INT_MAX;

        if(ans < INT_MIN) // if ans < 2^31
            ans = INT_MIN;

        return (int)ans;
    }
};