class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        vector<int>vis(n,-1);
        for(int i=0; i<n; i++){
           if(vis[i]==1) continue;
           queue<int>q;
           q.push(i);
           vis[i]=1;
           vector<int>component;
           while(q.size()>0){
            int node=q.front();
            q.pop();
            component.push_back(node);
            for(auto &neigh:adj[node]){
               if(vis[neigh]!=1){
                 vis[neigh]=1;
                 q.push(neigh);
               }
            }
           }
           bool complete=true;
           int k=component.size();
           for(auto &node:component){
            if(adj[node].size()!=k-1){
                complete=false;
                break;
            }
           }
           if(complete) ans++;
        }
        return ans;
    }
};