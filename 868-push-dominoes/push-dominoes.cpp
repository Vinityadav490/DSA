class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int>left(n);
        vector<int>right(n);
        for(int i=0; i<dominoes.size(); i++){
            if(dominoes[i]=='R') left[i]=i;
            else if(dominoes[i]=='.') left[i]=i>0?left[i-1]:-1;
            else left[i]=-1;
        }
        for(int i=n-1; i>=0; i--){
            if(dominoes[i]=='L') right[i]=i;
            else if(dominoes[i]=='.') right[i]=i<n-1?right[i+1]:-1;
            else right[i]=-1;
        }
        string res(n,' ');
        for(int i=0; i<n; i++){
            int dR=abs(i-right[i]);
            int dL=abs(i-left[i]);
            if(right[i]==left[i]) res[i]='.';
            else if(right[i]==-1) res[i]='R';
            else if(left[i]==-1) res[i]='L';
            else if(dR==dL) res[i]='.';
            else res[i]=dR<dL?'L':'R';
        }
        return res;
    }
};