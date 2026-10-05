class Solution {
public:
    bool isPossible(vector<int>&nums,int oprn,int mid){
         long long total=0;
         for(int&num:nums){
            int ops=(num-1)/mid;
            total+=ops;
         }
         if(total<=oprn) return true;
         else return false;
    } 
    int minimumSize(vector<int>& nums, int Operations) {
        
        int i=1;
        int j=*max_element(nums.begin(),nums.end());
        int ans=j;
        while(i<=j){
            int mid=i+(j-i)/2;
            int oprn=Operations;
            if(isPossible(nums,Operations,mid)){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};