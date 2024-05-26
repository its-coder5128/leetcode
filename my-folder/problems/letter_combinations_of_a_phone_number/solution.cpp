class Solution {
public:
    void solve(string &digits,int index,vector<vector<char>>& numSet,vector<string>& ans,string& temp)
    {
        if(index == digits.size())
        {
            if(temp.size() == digits.size())
                ans.push_back(temp);
            return;
        }
        vector<int> nums(10,0);
        for(int i = index;i<digits.size();i++)
        {
            int x = digits[i] - '0';
            while(nums[x] < numSet[x].size())
            {
                char c = numSet[x][nums[x]];
                nums[x]++;
                temp.push_back(c);
                solve(digits,i+1,numSet,ans,temp);
                temp.erase(temp.end()-1);
            }

            nums[x] = 0;
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        

        vector<vector<char>> numSet{
            {},
            {},
            {'a','b','c'},
            {'d','e','f'},
            {'g','h','i'},
            {'j','k','l'},
            {'m','n','o'},
            {'p','q','r','s'},
            {'t','u','v'},
            {'w','x','y','z'},
        };

        string temp = "";

        solve(digits,0,numSet,ans,temp);

        return ans;
    }
};