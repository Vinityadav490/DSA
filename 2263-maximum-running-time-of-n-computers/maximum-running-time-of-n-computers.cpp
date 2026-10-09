class Solution {
public:
    bool isPossible(long long mid,long long target,vector<int>&batteries){
        long long count=0;
        for(int i=0; i<batteries.size(); i++){
                count+=min((long long)batteries[i],mid);
                if(count>=target) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=1;
        long long h=accumulate(batteries.begin(),batteries.end(),0LL);
        h=h/n;
        long long ans=h;
        while(l<=h){
            long long mid=l+(h-l)/2;
            long long cnt=mid/(long long)n;
            if(isPossible(mid,n*mid,batteries)){
               ans=mid;
               l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};