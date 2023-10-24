class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> q;
        int time = 0;
        vector<int> arr(26,0);

        for(int i = 0;i<tasks.size();i++)
        {
            arr[tasks[i] - 'A']++;
        }
        for(int i = 0;i<26;i++)
        {
            if(arr[i])
            {
                q.push(arr[i]);
            }
        }

        while(!q.empty())
        {
            vector<int> temp;

            for(int i = 0;i<=n&&!q.empty();i++)
            {
                temp.push_back(q.top());
                q.pop();
            }

            for(int i = 0;i<temp.size();i++)
            {
                if(--temp[i]>0)
                    q.push(temp[i]);
            }

            time += q.empty() ? temp.size() : n+1;

        }

        return time;

        
    }
};