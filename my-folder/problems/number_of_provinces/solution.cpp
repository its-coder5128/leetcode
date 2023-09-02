class Solution {
public:
    // void dfs(unordered_map<int,list<int>> &adjList,vector<int> &visited,int node)
    // {
    //     visited[node] = 1;

    //     for(auto i:adjList[node])
    //     {
    //         if(!visited[i])
    //             dfs(adjList,visited,i);
    //     }
    // }
    int findCircleNum(vector<vector<int>>& isConnected) {

        unordered_map<int,list<int>> adjList;

        int n=isConnected.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> visited(n,0);
        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                queue<int> q;
                q.push(i);

                while(!q.empty())
                {
                    int temp = q.front();
                    q.pop();

                    for(auto node: adjList[temp])
                    {
                        if(!visited[node])
                        {
                            q.push(node);
                            visited[node] = 1;
                        }
                    }
                }
                cnt++;
            }
        }

        return cnt++;
        
    }
};