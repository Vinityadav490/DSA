class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<nums.size(); i++){
            nums[i]=nums[i]*nums[i];
        }
        long long sum=0;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        while(i<=j){
            if(i==j){
                sum+=nums[i];
                break;
            }
            sum+=(nums[j]-nums[i]);
            i++;
            j--;
        }
        return sum;
    }
};