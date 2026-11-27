class Solution {
public:
    long long minTime(vector<int>& skills, vector<int>& mana) {
        int n=skills.size();
        int m=mana.size();
        vector<long long>finish(n,0);
        for(int j=0; j<m; j++){
            finish[0]+=mana[j]*skills[0];
            for(int i=1; i<n; i++){
                finish[i]=max(finish[i],finish[i-1])+1LL*mana[j]*skills[i];
            }
            for(int i=n-1; i>0; i--){
                finish[i-1]=finish[i]-1LL*mana[j]*skills[i];
            }
        }
        return finish[n-1];
    }
};