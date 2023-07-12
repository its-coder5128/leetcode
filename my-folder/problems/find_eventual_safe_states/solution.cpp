class Solution {
public:
    bool dfsCycle(int node,unordered_map<int, bool> &visited,unordered_map<int, bool> &dfsVisited,
    vector<vector<int>>& graph,vector<int> &isSafe)
    {
        visited[node]=true;
        dfsVisited[node]=true;

        for(auto nb:graph[node])
        {
            if(!visited[nb])
            {
                bool cycle=dfsCycle(nb,visited,dfsVisited,graph,isSafe);

                if(cycle)
                {
                    isSafe[node]=0;
                    return true;
                }
            }
            else if(dfsVisited[nb])
            {
                isSafe[node]=0;
                isSafe[nb]=0;
                return true;
            }
        }

        dfsVisited[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> ans;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;


        int n=graph.size();
        vector<int> isSafe(n,1);

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bool isCycle=dfsCycle(i,visited,dfsVisited,graph,isSafe);
            }

        }

        for(int i=0;i<n;i++)
        {
            if(isSafe[i] == 1)
                ans.push_back(i);
        }

        return ans;
        
    }
};