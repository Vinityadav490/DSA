class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>>pq1;
        for(int i=0; i<grid.size(); i++){
            int limit=limits[i];
            priority_queue<int,vector<int>,greater<int>>pq2;
            for(int j=0; j<grid[0].size(); j++){
                pq2.push(grid[i][j]);
            }
            while(pq2.size()>limit){
                pq2.pop();
            }
            while(pq2.size()>0){
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
        while(pq1.size()>k){
            pq1.pop();
        }
        while(k--){
            sum+=pq1.top();
            pq1.pop();
        }
        return sum;
    }
};