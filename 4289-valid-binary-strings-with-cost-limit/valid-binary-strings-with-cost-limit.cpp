class Solution {
public:
    vector<string>all;
    void solve(int n,string &s,int k,vector<char>&binary){
        if(s.size()==n){
           int sum=0;
           bool yes=false;
           for(int i=0; i<s.size()-1; i++){
               if(s[i]=='1'&&s[i+1]=='1'){
                yes=true;
                break;
               }
           }
           if(yes==true) return;
           else{
            for(int i=0; i<s.size(); i++){
                if(s[i]=='1') sum+=i;
            }
            if(sum<=k){
                all.push_back(s);
            }
           }
            return;
        }
        for(int i=0; i<=1; i++){
            s.push_back(binary[i]);
            solve(n,s,k,binary);
            s.pop_back();
        }
        return;
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<char>binary({'0','1'});
        string s="";
        solve(n,s,k,binary);
        vector<string>ans;
        for(int i=0; i<all.size(); i++){
           string bs=all[i];
           int sum=0;
           bool yes=false;
           for(int i=0; i<bs.size()-1; i++){
               if(bs[i]=='1'&&bs[i+1]=='1'){
                yes=true;
                break;
               }
           }
           if(yes==true) continue;
           else{
            for(int i=0; i<bs.size(); i++){
                if(bs[i]=='1') sum+=i;
            }
            if(sum<=k){
                ans.push_back(bs);
            }
           }
        }
        return all;
    }
};