class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        const long long mod=1e9+7;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long >count(n,0);
        vector<long long>dp(k,0);
        dp[0]=1;
        for(int i=0; i<n; i++){
            long long sum=0;
            for(int j=0; j<k; j++) sum=(sum+dp[j])%mod;
            count[i]=sum;
            for(int j=k-1; j>=1; j--) dp[j]=(dp[j]+dp[j-1])%mod;
        }
        long long ans=0;
        for(int i=0; i<n; i++){
            long long mxCount=count[i];
            long long mnCount=count[n-1-i];
            long long cntri=nums[i]*(mxCount+mnCount)%mod;
            ans=(ans+cntri)%mod;
        }
        return ans;
    }
};