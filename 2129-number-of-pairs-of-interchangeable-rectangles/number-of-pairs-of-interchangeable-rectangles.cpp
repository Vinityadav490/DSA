class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        unordered_map<double,double>mp;
        long long count=0;
        for(int i=0; i<r.size(); i++){
            double n=(double)r[i][0]/r[i][1];
            if(mp.find(n)!=mp.end())count+=mp[n];
            mp[n]++;
        }
        return count;
    }
};