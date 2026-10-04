class Solution {
public:
    int minRotations(int n, string s) {
        vector<int>pre(n+1,0);
        pre[1] = min(s[0]-'0', 10-(s[0]-'0'));
        for(int i=1; i<s.size(); i++){
            int start=s[i]-'0';
            int end=s[i-1]-'0';
            int diff=abs(start-end);
            pre[i+1]=pre[i]+min(diff,10-diff);
        }
        int ans=pre[n];
        for(int k=0; k<n; k++){
            int steps=pre[k];
            if(k>0){
                int a=s[k-1]-'0';
                int b=s[n-1]-'0';
                int diff=abs(a-b);
                steps+=min(diff,10-diff);
            }
            else{
                int b=s[n-1]-'0';
                steps+=min(b,10-b);
            }
            steps+=pre[n]-pre[k+1];
            ans=min(ans,steps);
        }
        return ans;
    }
};