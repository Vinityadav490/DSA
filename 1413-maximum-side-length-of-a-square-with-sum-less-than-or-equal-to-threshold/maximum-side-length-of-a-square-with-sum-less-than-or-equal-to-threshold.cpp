class Solution {
public:
    bool isPossible(vector<vector<int>>&pre,int mid,int threshold){
        int n=pre.size();
        int m=pre[0].size();
        for(int i=mid-1; i<n; i++){
            for(int j=mid-1; j<m; j++){
                int x1=i-mid+1;
                int y1=j-mid+1;
                int sum=pre[i][j]-(x1>0?pre[x1-1][j]:0)-(y1>0?pre[i][y1-1]:0)+
                    (x1>0&&y1>0?pre[x1-1][y1-1]:0);
                    if(sum<=threshold) return true;

            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>pre=mat;
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++) pre[i][j]+=pre[i][j-1];
        }
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++) pre[i][j]+=pre[i-1][j];
        }
        int l=1;
        int h=min(n,m);
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(pre,mid,threshold)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};