class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int l=1;
        int h=1e9;
        int ans=0;
        while(l<=h){
            long long mid=l+(h-l)/2;
            long long req=mid*(mid+1)/2;
            if(req<=grades.size()){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};