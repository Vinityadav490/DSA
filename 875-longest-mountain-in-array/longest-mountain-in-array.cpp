class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int count=0;
        int ans=0;
        for(int i=1; i<arr.size()-1; i++){
            if(arr[i-1]<arr[i]&&arr[i+1]<arr[i]){
                int k=i;
                int j=i;
                while(j<arr.size()-1){
                    if(arr[j+1]>=arr[j]) break;
                    j++;
                }
                while(k>0){
                    if(arr[k-1]>=arr[k]) break;
                    k--;
                }
                ans=max(ans,j-k+1);
            }
        }
        return ans;
    }
};