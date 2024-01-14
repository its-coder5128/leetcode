class Solution {
public:
    bool closeStrings(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        if(n != m)
            return false;
        
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);

        for(int i = 0;i<n;i++)
        {
            arr1[word1[i]-'a']++;
            arr2[word2[i]-'a']++;
        }
    
        for(int i = 0;i<26;i++)
        {
            if(arr1[i] != 0)
            {
                cout<<arr1[i]<<" ";
                bool flag = true;
                for(int j = 0;j<26;j++)
                {
                    if(arr2[j] != 0 && arr1[j] != 0 && arr1[i] == arr2[j])
                    {
                        cout<<arr2[j]<<" ";
                        flag = false;
                        arr2[j] = 0;
                        break;
                    }
                }
                if(flag)
                    return false;
            }
        }

        return true;
        
    }
};