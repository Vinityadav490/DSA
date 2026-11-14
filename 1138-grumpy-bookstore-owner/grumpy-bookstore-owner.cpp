class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        int n=grumpy.size();
        for(int i=0; i<n; i++){
            if(grumpy[i]==0) sum+=customers[i];
        }
        int k=minutes;
        for(int i=0; i<k; i++){
            if(grumpy[i]==1) sum+=customers[i];
        }
        int ans=sum;
        for(int i=k; i<n; i++){
            if(grumpy[i-k]==1) sum-=customers[i-k];
            if(grumpy[i]==1) sum+=customers[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};