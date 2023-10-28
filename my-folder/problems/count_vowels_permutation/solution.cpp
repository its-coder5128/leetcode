class Solution {
public:
    int countVowelPermutation(int n) {

        vector<char> arr = {'a','e','i','o','u'};

        vector<int> previous(26,1);
        vector<int> curr(26,0);

        for(int i = 1;i<=n;i++)
        {
            for(int j = 0;j<5;j++)
            {
                char prev = arr[j];

                long long sum = 0;
                int MOD = 1e9 + 7;

                for(int k=0;k<5;k++)
                {
                    char c = arr[k];

                    if(i == n)
                        sum = (sum + (long long)previous[c-'a'])%MOD;
                    else
                    {
                        if(prev == 'a' && c == 'e')
                            sum = (sum + (long long)previous[c-'a'])%MOD;
                        else if(prev == 'e' && (c == 'a' || c == 'i'))
                            sum = (sum + (long long)previous[c-'a'])%MOD;
                        else if(prev == 'i' && c != 'i')
                            sum = (sum + (long long)previous[c-'a'])%MOD;
                        else if(prev == 'o' && (c == 'i' || c == 'u'))
                            sum = (sum + (long long)previous[c-'a'])%MOD;
                        else if(prev == 'u' && c == 'a')
                            sum = (sum + (long long)previous[c-'a'])%MOD;
                    }
                }

                curr[prev-'a'] = sum;

            }
            previous = curr;
        }

        return curr[0];
        
    }
};