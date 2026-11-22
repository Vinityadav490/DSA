class Solution {
public:
    int minRange(int a, int b, int c) {
        int ans=max({a,b,c})-min({a,b,c});
        int mx=max({a,b,c});
        if(mx==a) a=b+c;
        else if(mx==b) b=a+c;
        else c=a+b;
        return min(ans,max({a,b,c})-min({a,b,c}));
    }
};