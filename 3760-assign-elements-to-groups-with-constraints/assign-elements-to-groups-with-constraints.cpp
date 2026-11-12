class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n=groups.size();
        unordered_map<int,int>mp;
        for(int i=0; i<elements.size(); i++){
            if(mp.find(elements[i])==mp.end()) mp[elements[i]]=i;
        }
        vector<int>assign(n,-1);
        for(int i=0; i<n; i++){
            int g=groups[i];
            for(int j=1; j*j<=g; j++){
                if(g%j==0){
                    if(mp.find(j)!=mp.end()){
                        if(assign[i]==-1||mp[j]<assign[i]) assign[i]=mp[j];
                    }
                    int other=g/j;
                    if(mp.find(other)!=mp.end()){
                        if(assign[i]==-1||mp[other]<assign[i]) assign[i]=mp[other];
                    }
                }
            }
        }
        return assign;
    }
};