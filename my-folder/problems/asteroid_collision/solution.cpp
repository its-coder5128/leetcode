class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {

        vector<int> ans;
        int i = 0;
        while(i<=arr.size()-1)
        {
            if(!ans.empty() && arr[i] < 0 && ans.back() > 0 )
            {
                if(abs(arr[i]) > abs(ans.back()))
                {
                    ans.pop_back();
                }
                else if(abs(arr[i]) == abs(ans.back()))
                {
                    ans.pop_back();
                    i++;
                }
                else
                    i++;
            }
            else
            {
                ans.push_back(arr[i]);
                i++;
            }
        }

        return ans;
        
    }
};