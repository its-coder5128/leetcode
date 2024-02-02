class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> arr={1,2,3,4,5,6,7,8,9};

        vector<int> ans;

        for(int i = 0;i<9;i++)
        {
            int temp = 0;
            for(int j = i;j<9;j++)
            {
                // cout<<temp<<" "<<arr[j]<<endl;
                temp *= 10;
                temp += arr[j];
                if(temp >= low && temp<= high)
                    ans.push_back(temp);
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};