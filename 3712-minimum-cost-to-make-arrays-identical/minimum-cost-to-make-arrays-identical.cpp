class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& b, long long k) {
        if(a==b) return 0;
        long long ans1=0;
        long long ans2=k;
        for(int i=0; i<a.size(); i++){
            ans1+=abs(a[i]-b[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0; i<a.size(); i++){
            ans2+=abs(a[i]-b[i]);
        }
        return min(ans1,ans2);
    }
};