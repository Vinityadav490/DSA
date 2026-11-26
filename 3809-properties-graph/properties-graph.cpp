class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(auto neigh:adj[node]){
            if(vis[neigh]==-1){
                dfs(neigh,adj,vis);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        vector<vector<int>>adj(n);
        for(auto &v:properties){
            sort(v.begin(),v.end());
            v.erase(unique(v.begin(),v.end()),v.end());
        }
        for(int i=0; i<properties.size()-1; i++){
            for(int j=i+1; j<properties.size(); j++){
               int p=0;
               int q=0;
               int cnt=0;
                while(p<properties[i].size()&&q<properties[j].size()){
                    if(properties[i][p] == properties[j][q]){
                        cnt++;
                        p++;
                        q++;
                    }
                    else if(properties[i][p] < properties[j][q]){
                        p++;
                    }
                    else{
                        q++;
                    }
                } 
                if(cnt >= k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<int>vis(n,-1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};