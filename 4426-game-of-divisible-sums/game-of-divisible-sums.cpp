class Solution {
public:
    vector<long long>dp;
    long long solve(vector<int>&nums,int i){
        if(i>=nums.size()) return 0;
        if(dp[i]!=LLONG_MIN) return dp[i];
        long long sum=nums[i];
        long long take1;
        if(sum%3==0) take1=sum-solve(nums,i+1);
        else take1=sum+solve(nums,i+1);
        long long take2=LLONG_MIN;
        if(i+1<nums.size()){
            long long sum2=nums[i]+nums[i+1];
            if(sum2%3==0) take2=sum2-solve(nums,i+2);
            else take2=sum2+solve(nums,i+2);
        }
        return dp[i]=max(take1,take2);
    }
    long long maxDifference(vector<int>& nums) {
        dp.assign(nums.size(),LLONG_MIN);
        return solve(nums,0);
    }
};