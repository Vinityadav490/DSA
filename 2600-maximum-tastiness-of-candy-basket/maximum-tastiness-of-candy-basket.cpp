class Solution {
public:
    bool isPossible(vector<int>&price,int x,int k){
        int last = price[0], count = 1, i = 1;
            while (count < k && i < price.size()) {
                if (price[i] - last >= x)
                    last = price[i], count++;
                i++;
            }
            return count == k;
        }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int l=0;
        int h=1e9;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(price,mid,k)){
              l=mid+1;
              ans=mid;
            }
            else h=mid-1;
        }
        return ans;
    }
};