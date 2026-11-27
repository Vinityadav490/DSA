class Solution {
public:
    long long solve(int l,int r){
        long long L=1;
        long long s=1;
        long long steps=0;
        while(L<=r){
            long long R=4*L-1;
            long long start=max(L,(long long) l);
            long long end=min(R,(long long) r);
            if(start<=end) steps+=(end-start+1)*s;
            s+=1;
            L=L*4;
        }
        return steps;
    }
    long long minOperations(vector<vector<int>>& q) {
        long long count=0;
        for(int i=0; i<q.size(); i++){
            int l=q[i][0];
            int r=q[i][1];
            long long steps=solve(l,r);
            count+=(steps+1)/2;
        }
        return count;
    }
};