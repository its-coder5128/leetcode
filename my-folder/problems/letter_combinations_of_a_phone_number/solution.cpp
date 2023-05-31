class Solution {
private:
    void combination(string digits,string output,int index, vector<string> coll,vector<string> &ans)
    {
        if(index==digits.size())
        {
            if(output.empty())
            {
                return;
            }
            else
            {
                ans.push_back(output);
                return;
            }
        }

        

        //include
        
            int x=digits[index]-48-2;
            for(int i=0;i<coll[x].size();i++)
            {
                output.push_back(coll[x][i]);
                combination(digits,output,index+1,coll,ans);
                output.pop_back();

            }
                
            
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> coll{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string output="";
        int index=0;

        combination(digits,output,index,coll,ans);

        return ans;

    }
};