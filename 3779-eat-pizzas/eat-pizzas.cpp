class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end());
        long long sum=0;
        int n=pizzas.size();
        int i=n-1;
        int days=n/4;
        if(n==4) return pizzas[n-1];
        int evenDays=days/2;
        int oddDays=days-evenDays;
        while(oddDays>0){
            sum+=pizzas[i];
            i--;
            oddDays--;
        }
        i--;
        while(evenDays>0){
            sum+=pizzas[i];
            i-=2;
            evenDays--;
        }
        return sum;
    }
};