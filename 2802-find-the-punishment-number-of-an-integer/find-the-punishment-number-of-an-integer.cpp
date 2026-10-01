class Solution {
public:
    bool solve(vector<long long>&digit,int i,int sum,int target){
        int n=digit.size();
        if(i==n){
            if(sum==target) return true;
            return false;
        }
        int num=0;
        for(int j=i; j<n; j++){
            num=num*10+digit[j];
            if(solve(digit,j+1,sum+num,target)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int count=0;
        for(int i=1; i<=n; i++){
            long long prdt=1LL*i*i;
            vector<long long>digit;
            while(prdt>0){
                int d=prdt%10;
                digit.push_back(d);
                prdt/=10;
            }
            reverse(digit.begin(),digit.end());
            if(solve(digit,0,0,i)==true) count+=i*i;
        }
        return count;
    }
};