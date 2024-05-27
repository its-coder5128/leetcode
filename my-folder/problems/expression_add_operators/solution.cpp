class Solution {
public:
    void solve(int index,long long prevNum,string& num, int target,long long result,vector<string>& ans,string temp)
    {
        if(index == num.size())
        {
            if(result == target)
            {
                ans.push_back(temp);
            }
            return;
        }

        string numstr = "";
        long long number = 0; 
        for(int i = index;i<num.size();i++)
        {
            if(i > index && num[index] == '0') break;
            numstr += num[i];
            number = 10*number + (num[i] - '0');

            if(index == 0)
                 solve(i+1,number,num,target,number,ans,temp + numstr);
            else{
                solve(i+1,number,num,target,result+number,ans,temp + '+' + numstr);
            
                solve(i+1,-number,num,target,result-number,ans,temp + '-' + numstr);
        
                solve(i+1,prevNum*number,num,target,result-prevNum+prevNum*number,ans,temp + '*' + numstr);
            }
  

        }


        return;
        

    }
    vector<string> addOperators(string num, int target) {
        long long result = 0;

        vector<string> ans;

        string temp ="";

        solve(0,0,num,target,result,ans,temp);

        return ans;
    }
};