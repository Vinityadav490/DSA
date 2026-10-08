class Solution {
public:
    bool isPossible(int mid,vector<int>&nums,int p){
        int count=0;
        for(int i=1; i<nums.size(); i++){
           if(nums[i]-nums[i-1]<=mid){
            count++;
            i++;
            if(count==p) return true;
           }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l=0;
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        int h=mx-mn;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(mid,nums,p)){
               ans=mid;
               h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};