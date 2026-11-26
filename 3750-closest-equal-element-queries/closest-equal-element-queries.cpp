class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        vector<int> dist(n, -1);

        for(auto &it : mp){
            vector<int>& v = it.second;
            int m = v.size();

            if(m == 1) continue;

            for(int k = 0; k < m; k++){
                int idx = v[k];

                int prev = v[(k - 1 + m) % m];
                int next = v[(k + 1) % m];

                int d1 = abs(idx - prev);
                int d2 = abs(idx - next);

                d1 = min(d1, n - d1);
                d2 = min(d2, n - d2);

                dist[idx] = min(d1, d2);
            }
        }

        vector<int> ans;
        for(int q : queries)
            ans.push_back(dist[q]);

        return ans;
    }
};