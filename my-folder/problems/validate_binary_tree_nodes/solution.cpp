class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // unordered_map<int,list<int>> adjList;
        // for(int i=0;i<n;i++)
        // {
        //     int x = leftChild[i];
        //     int y = rightChild[i];     

        //     if(x != -1)
        //     {
        //         adjList[i].push_back(x);
        //     }
        //     if(y != -1)
        //     {
        //         adjList[i].push_back(y);
        //     }
        // }

        vector<int> rank(n,n);

        for(int i = 0;i<n;i++)
        {
            int x = leftChild[i];
            int y = rightChild[i];

            if(x != -1)
                rank[x]--;
            if(y != -1)
                rank[y]--;
        }

        int root = -1;

        for(int i = 0;i<n;i++)
        {
            if(rank[i] == n)
            {
                if(root == -1)
                    root = i;
                else
                    return false;
            }
        }
        if(root == -1)
            return false;

        queue<int> q;
        vector<int> vis(n,0);
        int cnt = 0;

                q.push(root);
                vis[root]=1;
                while(!q.empty())
                {
                    int front = q.front();
                    q.pop();
                    cnt++;

                    int nb = leftChild[front];
                        if(nb!= -1 && !vis[nb])
                        {
                            vis[nb] = 1;
                            q.push(nb);
                        }
                        else if(nb != -1)
                            return false;
                    nb = rightChild[front];
                        if(nb!=-1 && !vis[nb])
                        {
                            vis[nb] = 1;
                            q.push(nb);
                        }
                        else if(nb != -1)
                            return false;
                }
                
        
        if(cnt == n)
            return true;
        return false;
        
    }
};