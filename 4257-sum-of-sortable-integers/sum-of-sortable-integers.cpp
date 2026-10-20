class Solution {
public:
    bool solve(vector<int>nums,int k){
        int n=nums.size();
        int prevLast=INT_MIN;
        for(int i=0; i<n; i+=k){
            int desc=0;
            int start=i;
            for(int j=i; j<i+k; j++){
                int next=(j+1==i+k)?i:j+1;
                if(nums[j]>nums[next]){
                    desc++;
                    start=next;
                }
            }
            if(desc>1) return false;
            int first,last;
            if(desc==0){
                first=nums[i];
                last=nums[i+k-1];
            }
            else{
                first=nums[start];
                last=nums[start-1<i?i+k-1:start-1];
            }
            if(first<prevLast) return false;
            prevLast=last;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int k=1; k<=n; k++){
            if(n%k==0&&solve(nums,k)) sum+=k;
        }
        return sum;
    }
};