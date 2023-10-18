class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& time) {
        
        long long ans=0;
        vector<vector<int>> adj(n+1);
        vector<int> indeg(n+1,0);
        for(int i=0; i<r.size(); i++){
            
            adj[r[i][0]].push_back(r[i][1]);
            indeg[r[i][1]]++;
        }
        
        queue<int> q;
        vector<int> dist(n,0);
        for(int i=1; i<=n; i++){
            if(indeg[i]==0){
                q.push(i);
                // cout<<i<<" ";
                dist[i-1] = time[i-1];
            }
        }
        // cout<<endl;
        
        
        while(!q.empty()){
 
                int temp = q.front();
                q.pop();
                // count = max(count,time[temp-1]);
                
                // cout<<count<<endl;
                for(auto i: adj[temp]){
                    dist[i-1] = max(dist[i-1],dist[temp-1]+time[i-1]);
                    indeg[i]--;
                    if(indeg[i]==0){
                        q.push(i);
                    }
                
                
            }
            
        }
        return *max_element(dist.begin(),dist.end());
    }
};