class Solution {
public:
    void dfs(unordered_map<int,list<int>> &adjList,vector<int> &visited,vector<int> &done,int node,bool &flag)
    {
        if(done[node])
            return ;
        
        visited[node] = 1;

        for(auto nb : adjList[node])
        {
            if(!visited[nb])
            {
                dfs(adjList,visited,done,nb,flag);
            }
            else if(visited[nb] && !done[nb])
            {
                flag = false;
            }
        }

        if(!flag)
            return ;
        
        done[node] = 1;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,list<int>> adjList;

        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adjList[u].push_back(v);
        }

        vector<int> visited(numCourses,0);
        vector<int> done(numCourses,0);
        bool flag = true;

        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
                dfs(adjList,visited,done,i,flag);

            if(!flag)
                return false;

        }
        
        return true;
    
    }

};