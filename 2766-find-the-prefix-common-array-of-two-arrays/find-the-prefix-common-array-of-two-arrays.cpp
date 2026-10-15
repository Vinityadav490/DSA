class Solution {
public:
    int solve(int n,vector<int>&A,vector<int>&B){
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0; i<=n; i++){
            mp[A[i]]++;
        }
        for(int j=0; j<=n; j++){
            mp[B[j]]++;
        }
        for(auto it:mp){
            if(it.second>=2) count++;
        }
        return count;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i]=solve(i,A,B);
        }
        return ans;
    }
};