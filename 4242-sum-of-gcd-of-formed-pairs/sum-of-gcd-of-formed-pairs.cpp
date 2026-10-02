class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>mxi(n);
        mxi[0]=nums[0];
        for(int i=1; i<nums.size(); i++){
            mxi[i]=max(mxi[i-1],nums[i]);
        }
        for(int i=0; i<n; i++){
            pre[i]=gcd(nums[i],mxi[i]);
        }
        sort(pre.begin(),pre.end());
        long long sum=0;
        int sz=pre.size();
        int i=0;
        int j=sz-1;
        while(i<j){
            int num1=pre[i];
            int num2=pre[j];
            sum+=gcd(num1,num2);
            i++;
            j--;
        }
        return sum;
    }
};