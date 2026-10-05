class Solution {
public:
    bool isPossible(vector<int>& dist, long long mid, double hour) {
        double total = 0;

        for(int i = 0; i < dist.size() - 1; i++) {
            total += ceil((double)dist[i] / mid);
        }

        total += (double)dist.back() / mid;

        return total <= hour;
    }

    long long minSpeedOnTime(vector<int>& dist, double hour) {
        long long i = 1;
        long long j = 10000000;
        long long ans = -1;

        while(i <= j) {
            long long mid = i + (j - i) / 2;

            if(isPossible(dist, mid, hour)) {
                ans = mid;
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }

        return ans;
    }
};