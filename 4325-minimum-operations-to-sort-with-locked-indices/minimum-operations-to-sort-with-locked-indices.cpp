class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int oprn=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size()-1; j++){
                if(nums[j+1]<nums[j]){
                   if(locked[j]==1){
                     if(k==0) return -1;
                     oprn++;
                     locked[j]=0;
                     k--;
                   }
                   if(locked[j+1]==1){
                     if(k==0) return -1;
                     oprn++;
                     locked[j+1]=0;
                     k--;
                   }
                   swap(nums[j],nums[j+1]);
                   oprn++;
                }
            }
        }
         return oprn;
    }
};