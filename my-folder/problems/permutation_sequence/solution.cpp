class Solution {
public:
    string getPermutation(int n, int k) {
        k=k-1;

        int fact=1;
        vector<int> arr;

        for(int i=1;i<n;i++)
        {
            arr.push_back(i);
            fact=fact*(i);
        }
            arr.push_back(n);

        string ans="";

        while(true)
        {
            ans=ans + to_string(arr[k/fact]);

            arr.erase(arr.begin()+k/fact);

            if(arr.size() == 0)
            {
                break;
            }

            k=k%(fact);
            fact=fact/arr.size();
        }

        return ans;
    }
};