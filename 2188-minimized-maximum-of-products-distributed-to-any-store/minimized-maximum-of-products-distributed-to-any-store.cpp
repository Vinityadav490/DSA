class Solution {
public:
    bool isPossible(int mid,int shops,vector<int>&quantities){
        for(auto &product:quantities){
           shops-=(product+mid-1)/mid;
           if(shops<0) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int l=1; 
        int h=*max_element(quantities.begin(),quantities.end());
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(mid,n,quantities)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};