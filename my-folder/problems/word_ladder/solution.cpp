class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(),wordList.end());

        if(dict.find(endWord) == dict.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int ans = 1;

        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0;i<n;i++)
            {
                string str = q.front();
                q.pop();

                if(str == endWord)
                    return ans;

                for(int j = 0;j<str.size();j++)
                {
                    string temp = str;
                    for(int k=0;k<26;k++)
                    {
                        temp[j] = 'a' + k;

                        if(dict.find(temp) != dict.end())
                        {
                            q.push(temp);
                            dict.erase(temp);
                        }
                    }
                }
            }
            ans++;
        }

        return 0;
        
    }
};