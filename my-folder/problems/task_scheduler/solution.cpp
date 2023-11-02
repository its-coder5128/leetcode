class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> m;

        for(int i = 0;i<tasks.size();i++)
        {
            m[tasks[i]]++;
        }

        priority_queue<int> q;

        for(auto i : m)
        {
            q.push(i.second);
        }

        int time = 0;
        while(!q.empty())
        {
            vector<int> temp;
            temp.push_back(q.top());
            q.pop();

            for(int i = 0 ;i<n&&!q.empty();i++)
            {
                temp.push_back(q.top());
                q.pop();
            }
            int x = temp.size();

            for(int i = 0;i<x;i++)
            {
                temp[i]--;
                if(temp[i] > 0)
                    q.push(temp[i]);
            }

            if(q.empty())
                time += x;
            else
                time += n + 1;
        }
        
        return time;
    }
};