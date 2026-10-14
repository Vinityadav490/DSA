class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long ans=0;
        int count=0;
        long long lower=1000;
        int comma=1;
        while(lower<=n){
            long long upper=lower*1000-1;
            if(upper>n) upper=n;
            long long count_no=upper-lower+1;
            ans+=(count_no*comma);
            lower=lower*1000;
            comma+=1;
        }
        return ans;
    }
};